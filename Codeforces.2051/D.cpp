/*
 * Created: 2024-12-25
 * Author: @adnanebenazzou
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
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<int> a;
	ll sum = 0; 
	int tmp;
	
	for (int i = 0; i < n; i ++) {
		cin >> tmp;
		a.push_back(tmp);
		sum += a[i];
	}
	
	ll X = sum - x;
	ll Y = sum - y;
	dbg(X, Y, sum);
	
	sort(all(a));
	
	ll res = 0;
	ll tmpX, tmpY;
	for (int i = 0; i < n - 1; i ++ ) {
		tmpX = X - a[i];
		tmpY = Y - a[i];
		
		dbg(a[i], tmpY, tmpX);
		auto lb = lower_bound(a.begin() + i + 1, a.end(), tmpY);
		
		auto ub = upper_bound(a.begin() + i + 1, a.end(), tmpX);
		
		dbg (*lb, *ub);		
		// check if lb exists i.e lb not equal to last element.
		//if (lb == a.end()) {
			// all elements too small - > end - end, case already covered
			//continue;
		//}
		// also check if ub exists.
		// if all elements are small enough, it will return a.end() which is correct;
		dbg(ub - lb);
	
		res += ub - lb;
	}
	
	cout << res << '\n';
	

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
