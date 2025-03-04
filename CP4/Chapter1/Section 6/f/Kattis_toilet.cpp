
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

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int adj[3] = {0, 0, 0};
	char prev_state = s[0];
	if (prev_state == 'U' && s[1] != prev_state) {
		// initial is UP and user wants DOWN
		// if strategy is UP + 2
		// if strategy is DOWN +1
		adj[0] = 2;
		adj[1] = 1;
		adj[2] = 1;
	} else if (prev_state == 'D' && s[1] != prev_state) {
		// initial is DOWN and user wants UP
		adj[0] = 1;
		adj[1] = 2;
		adj[2] = 1;
	} else if (prev_state == 'U') {
		// strategy down -> change down 
		adj[1] = 1;
	} else {
		// strategy up -> change up
		adj[0] = 1;
	}
	prev_state = s[1];// for adj2
	for (int i = 2; i < n; i ++) {
		int adjust = (s[i] == 'U') ? 1 : 0;
		adj[adjust] += 2;

		if (prev_state != s[i]) {
			// previous one left it not as i wanted
			// change it and leave
			adj[2] ++;
			prev_state = s[i];
		}

		/*
		if (s[i] == 'U') {
			// strat 1 is always leave up -> no interaction
			// strat 2 is always down -> switch to up, then switch back to down
			adj[1] += 2;
			
		} else if (s[i] == 'D') {
			// strat 2 is always down -> no interaction
			// strat 1 -> down then up
			adj[0] += 2;
		}
		*/

	}
	for (int i = 0; i < 3; i ++) {
		cout << adj[i] << '\n';
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

