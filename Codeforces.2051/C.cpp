/*
 * Created: 2024-12-24
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
	int n, m, k;
	cin >> n >> m >> k;
	int a[m];
	for (int i = 0; i < m; i ++) {
		cin >> a[i];
		dbg(a[i], i);
	}
	
	int q[k];
	for (int i = 0; i < k; i ++) {
		cin >> q[i];
		dbg(q[i], i);
	}
		
	bool allPass = false;
	bool allFail = false;
	string res = "";
	int noAnswer;

	if (k >= n) {
		allPass = true;
	}
	else if ( k < n - 1) {
		allFail = true;
	}
	else {
		sort(q, q + k);
		dbg(q);
		for (int i = 1; i <= n; i ++) {
			if (i > k) {
				noAnswer = i;
			}
			else if (q[i - 1] != i) {
				dbg(q[i - 1]);
				dbg(i);
				noAnswer = i;// question to which he does not have an answer
				dbg(noAnswer);
				break;
			}
		}
	}
	for ( int i = 0;i < m; i++) {
		if (allPass) {
			res += "1";
		} else if (allFail) {
			res += "0";
		} else {
			res += (a[i] == noAnswer)?"1":"0";// if we are removing the question without answer passs, else fail
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    
    for (int i = 1; i <= tc; i ++ ) {
		//dbg("Test Case: ", i);
		solve();
	}

	return 0;
}
