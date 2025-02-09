
/*
 * Author: @adnanebenazzou
 */

#include <bits/stdc++.h>
#include <cmath>

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
	int n, m;
	cin >> n >> m;
	int a[n]; 
	vi b(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	a[0] = min(a[0], b[0] - a[0]);
	// a should be minimal
	for (int i = 1; i < n ; i ++) {	
		auto lb = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
		if (lb != b.end()) {
			if (a[i] < a[i - 1]) {
				// the smallest number so that ub >= a[i] + a[i - 1]
				a[i] = *lb - a[i];
			} else {
				// make sure it is the smallest
				a[i] = min(*lb - a[i], a[i]);
			}
		}
	}
	bool isValid = true;
	for (int i = 1; i < n ; i ++) {
		if (a[i] < a[i - 1]) {
			isValid = false;
			break;
		}
	}
	cout << (isValid ? "YES" : "NO" ) << '\n';
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

