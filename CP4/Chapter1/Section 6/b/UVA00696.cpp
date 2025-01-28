
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


void solve() {
	int m, n;
	while(scanf("%d %d", &m, &n) && (m || n)) {
		if (n < 2 || m < 2) {
			cout << m * n ; // either 0 or full line
		}
		else if (m == 2 || n == 2) {
			int tmp = max(m, n);
			cout << 4 * (tmp /4) + 2 * min(2, tmp % 4); // how many pair of 2 can i fit into how many pairs of 1 left to fit
	       }
		else {
			cout << (((m + 1) / 2) * ((n + 1) / 2) + ((m/2) * (n/2))); 

			// cout << (m * n + 1) / 2; // 1 knight every 2 square + ceil
		}

		cout << " knights may be placed on a " << m << " row " << n << " column board.\n";
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

