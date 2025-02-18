
/*
 * Author: @adnanebenazzou
 */

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

//#define LOCAL
#define all(a) (a).begin(), (a).end()

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

ll power(ll x, int exp, ll m)
{
    x %= m;
    ll res = 1;
    while (exp)
    {
	// if odd x ^ exp = x * x ^ exp - 1
        if (exp & 1) res = res * x % m;
        x = x * x % m;
        exp >>= 1;
    }
    return res;
}

int get_card_number(int card_idx) {

	// 0 -> 12, 13 ->25 ....
	return card_idx % 13;
}

int get_card_idx(string card)  {

	int idx = 0;
	switch(card[1]) {
		case 'S': break;
		case 'H' : {
			idx ++;
			break;
		}
		case 'D' : {
			idx += 2;
			break;

		}
		case 'C' : {
			idx += 3;
			break;
		}
	}
	idx *= 13;
	switch (card[0]) {
		case 'A': break;
		case 'T': {
			idx += 9;
			break;
		}
		case 'J': {
			idx += 10;
			break;
		}
		case 'Q': {
			idx += 11;
			break;
		}
		case 'K': {
			idx += 12;
			break;
		}
		default: {
			idx += (card[0] - '0') - 1;
			break;
		}
	}
	return idx;
}

string get_card_string(int idx) {

	int num = get_card_number(idx);
	string card;
	switch(num) {
		case 0: {
			card = "A";
			break;
		}
		case 9: {
			card = "T";
			break;
		}
		case 10: {
			card = "J";
			break;
		}

		case 11: {
			card = "Q";
			break;
		}

		case 12: {
			card = "K";
			break;
		}
		default: {
			card = to_string(num + 1);
			break;
		}

	}
	int house = idx / 13;

	switch(house) {
		case 0: {
			card += "S";
			break;
		}
		case 1: {
			card += "H";
			break;
		}
		case 2: {
			card += "D";
			break;
		}
		case 3: {
			card += "C";
			break;
		}
	}

	return card; 
}

int get_prize(vi freq) {

	// run4, run 3
	vector<bool> isRun(3, false);
	for (int i = 0; i < 13; i ++) {
		if (freq[i] == 0) continue;
		for (int j = 1; j < 5; j ++) {
			if (freq[(i + j) % 13] == 0) break;
			if (j == 4) return 100; // run of 5 is best result return
			else if (j == 3) isRun[0] = true; // run of 4
			// run of 3 and 2 will be done separately
			// because we need to track frequency for each possible combination
		}
	}
	if (isRun[0]) return 10; // not run 5
	// 3 or 3 + 2
	for (int i = 0; i < 13; i ++) {
		if (freq[i] == 0) continue;
		for (int j = 1; j < 3; j ++) {
			if (freq[(i + j) % 13] == 0) break;
			if (j == 2) isRun[1] = true;
		}
		if (isRun[1]) {
			vi freq_run3(freq);
			freq_run3[i] --;
			freq_run3[(i + 1) % 13] --;
			freq_run3[(i + 2) % 13] --;
			// do we have a run of 2
			for (int j = 0; j < 13; j ++) {
				if (freq_run3[j] == 0) continue;
				if (freq_run3[(j + 1) % 13] > 0) return 5; // run of 3 + 2
			}
			// if we didnt return, run of 3 only
			// no other possible 3 + 2 bcz otherwise it would be 4+
			return 3;
		}
	}
	// 2 + 2
	for (int i = 0; i < 13; i ++) {
		if (freq[i] == 0) continue;
		if (freq[(i + 1) % 13] > 0) {
			vi freq_run2(freq);
			// run of 2
			freq_run2[i] --;
			freq_run2[(i + 1) % 13] --;
			// do we have another run of 2?
			for (int j = 0; j < 13; j ++) {
				if (freq_run2[j] == 0) continue;
				if (freq_run2[(j + 1) % 13] > 0) return 1; // run of 2 + 2
			}
		}
	}
	return 0;
}

int get_max_exchange_card(vi freq, int card_num) {
	// exchange card_idx and compute
	int expected_prize = 0;
	for (int i = 0; i < 13; i ++) {
		vi freq_exchange(freq);
		int num_exchanges = 4 - freq[i]; // possible times to get this card e.g if we have an Ace we can get 3 others but if we dont we can get 4
		freq_exchange[card_num] --;
		freq_exchange[i] ++;
		expected_prize += num_exchanges * get_prize(freq_exchange);
	}
	return expected_prize;
}

void solve() {
	string s;
	while(getline(cin, s) && s != "#") {
		istringstream iss(s);
		string tmp;
		// S H D C
		// 0 -> 12
		vi freq(13, 0), hand;
		int idx;
		for (int i = 0; i < 5; i ++) {
			// 5 cards
			iss >> tmp;
			idx = get_card_idx(tmp);
			hand.push_back(idx);
			freq[get_card_number(idx)] ++;
		}

		int prize = (get_prize(freq) - 1) * 47;

		int expected_prize;
		string res = "Stay";
		for (int i = 0; i < 5; i ++) {
			// exchange card idx with every other possible card
			expected_prize = get_max_exchange_card(freq, get_card_number(hand[i])) - 94;
			if (expected_prize > prize) {
				res = "Exchange " + get_card_string(hand[i]);
				prize = expected_prize;
			}
		}
		cout << res << '\n';

	}
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

