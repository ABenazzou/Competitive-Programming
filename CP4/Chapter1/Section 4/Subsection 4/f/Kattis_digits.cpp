/*
 * Created: 2025-01-06
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

int recurse(string n, int prev, int level) {
	// xi + 1 = num digits xi
	// we start with level = 0
	int digits = n.length();
	// is this the same as the previous one?
	dbg(n, prev, level, digits);
	if (level == 1 && n == "1") return level;
	else if (level != 1 && digits == prev) {
		return level;
	}
	
	return recurse(to_string(digits), digits, ++level);
	
	
}

void solve() {
	 string s, prev;
	 while(getline(cin, s) && s != "END") {
		 cout << recurse(s, 0, 1) << '\n';
	 }
	
}


int main() {
	//ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}
