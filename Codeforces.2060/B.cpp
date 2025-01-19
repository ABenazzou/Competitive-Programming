
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
bool cmp(ii& a, ii& b) {
	return a.second < b.second;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int cows[n][m];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf("%d", &cows[i][j]);
		}
	}
	vector<ii> permutation;
	for (int i = 0; i < n; i ++) {
		sort(cows[i], cows[i] + m);
		permutation.push_back(make_pair(i, cows[i][0])); 
	}
	sort(permutation.begin(), permutation.end(), cmp);

	for (int i = 0; i < m; i ++) {
		for (int j = 1; j < n; j ++) {
			if (cows[permutation[j].first][i] <= cows[permutation[j - 1].first ][i]) {
				dbg(i, j, permutation);
				cout << -1 << '\n';
				return;
			}
		}
		if (i != m - 1 && cows[permutation[n - 1].first][i] >= cows[permutation[0].first][i + 1]) {
			dbg(i, 0, permutation);
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << permutation[i].first + 1;
		if (i != n -1) {
			cout << " ";
		} else {
			cout << '\n';
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

