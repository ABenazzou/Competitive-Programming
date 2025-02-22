
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

// judge unavailable, test against accepted test cases for last input and compare diff --> AC
void solve() {
	// front last first
	// baclk last -1 first + 1
	int n;
	while (cin >> n && n) {
		cout << "Printing order for " << n << " pages:\n";
		int total = ceil(n * 0.25);
		bool skip = false;
		for (int i = 1; i <= total; i ++) {
			if (skip) break;
			int page1 = (i - 1) * 2 + 1;// 1, 3, ...
			int page4 = total * 4 - page1 + 1;// 4*total, 4*total - 2, ...
			// page 1 will always be full
			string ans1 = (page4 <= n)? to_string(page4) : "Blank";
			string ans2 = to_string(page1);
			string ans3 = (page1 + 1 <= n)? to_string(page1 + 1) : "Blank";
			string ans4 = (page4 - 1 <= n)? to_string(page4 - 1) : "Blank";
			skip = (ans3 == "Blank" && ans4 == "Blank");
			// page1 will always be full, skip starts from back
			cout << "Sheet " << i << ", front: " << ans1 << ", " << ans2 << '\n';
			if (!skip) cout << "Sheet " << i << ", back : " << ans3 << ", " << ans4 << '\n';
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

