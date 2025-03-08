
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

void showDisplay(vector<vector<char>> grid, int n, int m) {
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}

}

void solve() {
	int n, s;
	while (cin >> s >> n && (n || s)) {
		// s + 2 col, 2 as + 3 row
		int digitLength = 2 * s + 3, digitWidth= s + 2;
		string _n = to_string(n);
		int len = _n.length();
		// the display will have: digit empty digit empty digit empty digit | digit -> len*digits + len - 1 (for spaces) -> len(digits + 1) - 1
		vector<vector<char>> display(2 * s + 3, vector<char>(len * (digitWidth + 1) - 1, ' '));
		int gridPos = 0;
		for (int i = 0; i < len; i ++) {
			if (_n[i] == '0') {
				// e s e
				// s e s
				// e e e
				// s e s
				// e s e
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + l + 1] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < digitLength - 1; k ++) {
					if (k == s + 1) continue;
					display[k][gridPos] = '|';
					display[k][gridPos + digitWidth - 1] = '|';
				}

			} else if (_n[i] == '1') {
				// s1 5 empty 1 bar empty 1 bar empty
				// s2 7 e 2 e 2 e
				// s3 9 e 3 e 3 e 
				// draw s times from i = 1 (s + 1), then s times from i = s + 2 s times (2 s + 2)
				for (int k = 1; k < digitLength - 1; k ++) {
					if (k == s + 1) continue;
					display[k][gridPos + digitWidth - 1] = '|';
					// draw on the last pos of the number
				}

			} else if (_n[i] == '2') {
				// e s e
				// e e s
				// e s e
				// s e e
				// e s e
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[s + 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < s + 1; k ++) {
					display[k][gridPos + digitWidth - 1] = '|';
				}
				for (int k = s + 2; k < digitLength - 1; k ++) {
					display[k][gridPos] = '|';

				}

			} else if (_n[i] == '3') {
				// e s e
				// e e s
				// e s e
				// e e s
				// e s e
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[((digitLength - 1) / 2)][gridPos + l + 1] = '-';

				}
				for (int k = 1; k < digitLength - 1; k ++) {
					if (k == s + 1) continue;
					display[k][gridPos + digitWidth - 1] = '|';
				}
				
			} else if (_n[i] == '4') {
				// e e e 
				// s e s
				// e s e
				// e e s
				for (int l = 0; l < s; l ++) {
					display[s + 1][gridPos + l + 1] = '-';

				}
				for (int k = 1; k < s + 1; k ++) {
					display[k][gridPos] = '|';
					display[k][gridPos + digitWidth - 1] = '|';
				}
				for (int k = s + 2; k < digitLength - 1; k ++) {
					display[k][gridPos + digitWidth - 1] = '|';
				}

			} else if (_n[i] == '5') {
				// reverse 2
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[s + 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < s + 1; k ++) {
					display[k][gridPos] = '|';
				}
				for (int k = s + 2; k < digitLength - 1; k ++) {
					display[k][gridPos + digitWidth - 1] = '|';

				}
			
			} else if (_n[i] == '6') {
				// 5 with initialized 0
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[s + 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < s + 1; k ++) {
					display[k][gridPos] = '|';
				}
				for (int k = s + 2; k < digitLength - 1; k ++) {
					display[k][gridPos + digitWidth - 1] = '|';
					display[k][gridPos] = '|';

				}
			
			} else if (_n[i] == '7') {
				// 3 without middle and end
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';

				}
				for (int k = 1; k < digitLength - 1; k ++) {
					if (k == s + 1) continue;
					display[k][gridPos + digitWidth - 1] = '|';
				}
				
			} else if (_n[i] == '8') {
				// 6 wit side or 0 with middle
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[s + 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < digitLength - 1; k ++) {
					if (k == s + 1) continue;
					display[k][gridPos + digitWidth - 1] = '|';
					display[k][gridPos] = '|';

				}

			} else if (_n[i] == '9') {
				// 6 with reversed side 
				for (int l = 0; l < s; l ++) {
					display[0][gridPos + 1 + l] = '-';
					display[digitLength - 1][gridPos + l + 1] = '-';
					display[s + 1][gridPos + l + 1] = '-';
				}
				for (int k = 1; k < s + 1; k ++) {
					display[k][gridPos] = '|';
					display[k][gridPos + digitWidth - 1] = '|';
				}
				for (int k = s + 2; k < digitLength - 1; k ++) {
					display[k][gridPos + digitWidth - 1] = '|';

				}
				
			
			}
			gridPos += digitWidth + 1; // one digit + 1 space
		}
		showDisplay(display, 2 * s + 3, len * (digitWidth + 1) - 1);
		cout << '\n';
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

