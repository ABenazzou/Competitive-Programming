
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

int addValues(string s, int n, bool isDigitResult) {
	int res = 0;
	for (int i = 0; i < n; i ++) {
		res += s[i] - '0';
	}
	string newS = to_string(res);
	int newN = newS.length();
	if (newN > 1 && isDigitResult) return addValues(newS, newN, isDigitResult);
	return res;
}
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = n - 2; i >= 0; i -= 2) {
		dbg(i);
		int digit = s[i] - '0';
		digit *= 2;
		dbg(digit);
		string newS = to_string(digit);
		int newN = newS.length();
		s[i] = addValues(newS, newN, true) + '0';
		dbg(s);
	}
	int res = addValues(s, n, false);
	cout << ((res % 10 == 0) ? "PASS" : "FAIL") << '\n';
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

