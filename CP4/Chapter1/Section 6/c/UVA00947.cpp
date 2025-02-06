
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

double power(double base, int exp) {
	if(exp == 0) return 1;
	if(exp < 0) return 1 / power(base, -exp);
	double result = power(base, exp / 2);
	if (exp % 2 == 0) {
		return base * base;
	}
	else {
		return base * result * result;
	}
}

int RESULT;
map<int, set<int>> letter_to_pos;
map<int, int> freq_letters;
int correct, wrong;
set<int> visited;

bool is_valid_combination(string backTrackBase) {
	int corr = 0, wrng = 0;
	map<int, int> freq;
	int n = backTrackBase.length();
	for (int i = 0; i < n; i ++) {
		if (letter_to_pos.find(backTrackBase[i] - '0') != letter_to_pos.end()) {
			// letter exists, we only increment if good pos or bad pos but if its freq is already at max, no increment
			if (freq.find(backTrackBase[i] - '0') == freq.end()) freq[backTrackBase[i] - '0'] = 0;

			// if freq of number < its max freq consider else skip 
			// 155 freq is 1 so 0 < 1 but 1 is not
			if (freq[backTrackBase[i] - '0'] < freq_letters[backTrackBase[i] - '0']) {
				//we can add this letter bcz it didnt reach max yet
				if (letter_to_pos[backTrackBase[i] - '0'].find(i) != letter_to_pos[backTrackBase[i] - '0'].end()) {
					// if current idx exists in that char indexes;
					corr ++;
				} else {
					wrng ++;
				}
			}
			else {
				// we re over the max but if its a good pos, wrng -- 
				// bcz the other one will not be considered
				// e.g. the other one is not good color bcz additional

				if (letter_to_pos[backTrackBase[i] - '0'].find(i) != letter_to_pos[backTrackBase[i] - '0'].end()) {
					corr ++;
					wrng --;
				}

			}
			freq[backTrackBase[i] - '0'] ++;
			

		}
	}
	// same number of corr positions and wrong positions
	return corr == correct && wrong == wrng;
}

void generate_code(string base, int limit) {
	string newCode, backTrackBase;
	int n = base.length();
	for (int i = 1; i < 10; i ++) {
		backTrackBase = base + to_string(i);
		// generate possibilities if we can still add a letter
		if (n + 1 < limit) {
			generate_code(backTrackBase, limit);
		} else if (n + 1 == limit) {
			if (visited.find(stoi(backTrackBase)) != visited.end()) continue; // if we found it previously dont check
			// limit == n - 1 and we added a letter
			// so we need to check if the combi is valid
			if (is_valid_combination(backTrackBase)) {
				visited.insert(stoi(backTrackBase));
				RESULT ++;
			}

		}
		// backtrack
	}
}

void solve() {
	int res;
	cin >> res >> correct >> wrong;
	string s = to_string(res);
	int n = s.length();
	RESULT = 0;
	freq_letters.clear();
	visited.clear();
	letter_to_pos.clear();
	for (int i = 0; i < n; i ++) {
		if (letter_to_pos.find(s[i] - '0') == letter_to_pos.end()) {
			set<int> tmp;
			letter_to_pos[s[i] - '0'] = tmp;
		}
		letter_to_pos[s[i] - '0'].insert(i);
		if (freq_letters.find(s[i] - '0') == freq_letters.end()) freq_letters[s[i] - '0'] = 0;
		freq_letters[s[i] - '0'] ++;
	}
	generate_code("", n);
	dbg(visited);
	cout << RESULT << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

