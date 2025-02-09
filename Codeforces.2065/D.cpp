
/*
 * Author: @adnanebenazzou
 */

#include <bits/stdc++.h>
#include <queue>

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
	vector<vi> a(n, vi(m));
	priority_queue<pair<long long, int>> sumsOrder;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
		}
		ll sum = accumulate(a[i].begin(), a[i].end(), 0LL);
		dbg(sum);
		sumsOrder.push(make_pair(sum, i));
	}
	vector<int> concatenated;
	while (!sumsOrder.empty()) {
		pair<long long, int> tmp = sumsOrder.top();
		sumsOrder.pop();
		for (int i = 0; i < m; i ++) {
			concatenated.push_back(a[tmp.second][i]);
		}
	}
	vector<long long> res(n * m);
	dbg(concatenated);
	res[0] = concatenated[0];
	for (int i = 1; i < n * m;i ++) {
		res[i] = concatenated[i] + res[i - 1];
	}
	cout << accumulate(res.begin(), res.end(), 0LL) << '\n';
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

