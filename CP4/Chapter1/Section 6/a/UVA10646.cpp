
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


void solve(int tc) {

	string deck[52];
	for(int i = 0; i < 52; i ++) {
		cin >> deck[i];
	}
	cout << "Case " << tc << ": " << deck[32] << '\n';
/*	char tmp;
	int Y = 0, value, topCard = 24;
	for (int i = 0; i < 3; i ++) {
		tmp = deck[topCard][0];
		if (isdigit(tmp)) {
			value = tmp - '0';
		} else {
			value = 10;
		}
		Y += value;
		topCard -= 11 - value; // 10 cards + current card - x
	}
	if (Y - 1 <= topCard) { // sum xi - 1 <= 24 - sum xi - 11 * 3 - > -1 <= 24 - 33 impossible
		cout << deck[Y - 1] << '\n';
	} else {
		int idx = 23 + Y - topCard; // 23 + sum xi - 24 - sum xi + 11 * 3 -> 32
		cout << deck[idx] << '\n';
	}
	dbg(Y, topCard);
	*/
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve(i);
	}

	return 0;
}

