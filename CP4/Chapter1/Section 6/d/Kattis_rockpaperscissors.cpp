
/*
 * Author: @adnanebenazzou
 */

#include <bits/stdc++.h>
#include <ios>

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

void solve() {
	int n, k;
	int tc = 0;
	while (cin >> n && n) {
		if (tc != 0) cout << '\n';
		tc ++;
		cin >> k;
		vii players(n , {0, 0});
		int p1, p2;
		string m1, m2;
		for (int i = 0; i < (k * n * (n - 1) / 2); i ++) {
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 == m2) {
				continue;
			}
			else if ((m1 == "rock" && m2 == "paper") || (m1 == "paper" && m2 == "scissors") || (m1 == "scissors" && m2 == "rock")) {
				players[p2 - 1].first ++;
			} else { 
				players[p1 - 1].first ++;
			}
			// increment game count wether they won or lost
			players[p2 - 1].second ++;
			players[p1 - 1].second ++;
		}

		for (ii result: players) {
			if (result.second == 0) {
				cout << "-\n";
			} else {
				double res = (1.0 * result.first / result.second);
				cout << fixed << setprecision(3) << res << '\n';
			}
		}

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

