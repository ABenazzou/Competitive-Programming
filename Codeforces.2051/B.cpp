/*
 * Created: 
 * Author: @adnanebenazzou
 * File: 
 */

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
//#define LOCAL

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int abc = a + b + c;
	int res = (n / abc);
	res *= 3;
	int left = n % abc;
	dbg(res, left, abc);
	
	if (left == 0) {
		cout << res << '\n';
	}
	else if (left <= a) {
		cout << res + 1 << '\n';
	}
	else if (left <= a + b) {
		cout << res + 2 << '\n';
	}
	else if (left <= abc) {
		cout << res + 3 << '\n'; // case of abcabc where abcabc is enough but abcab is not i.e. 1 2 4 1 2 4 and n = 11
	}

}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}
