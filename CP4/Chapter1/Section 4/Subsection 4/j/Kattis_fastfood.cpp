
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


void solve() {
	int n, m;
	scanf("%d %d", &n , &m);
	priority_queue<pair<int, vector<int>>> prizes; // [(cash, [combination)
	int k, cash;
	for (int i = 0; i < n; i ++) {
		scanf("%d", &k);
		vector<int> tmpV;
		int tmp;
		for (int j = 0; j < k; j ++) {
			scanf("%d", &tmp);
			tmpV.push_back(tmp);
		}
		scanf("%d", &cash);
		prizes.push(make_pair(cash, tmpV));
	}
	map<int, int> freq;
	int tmp;
	for (int i = 0; i < m; i ++) {
		scanf("%d", &tmp);
		freq[i + 1] = tmp;
	}
	// iterate over cash prizes and check if its possible to claim it
	// it should be guaranteed to have max sum due to priority queue
	int tmpCash;
	vector<int> types;
	bool possiblePrize;
	int res = 0, maxClaims;
	while (!prizes.empty()) {
		maxClaims = INF;
		tmpCash = prizes.top().first;
		types = prizes.top().second;
		dbg(types, tmpCash, freq);
		possiblePrize = true;
		int N = types.size();
		for (int i = 0; i < N; i ++) {
			if (freq.find(types[i]) == freq.end() || freq[types[i]] <= 0) {
				possiblePrize = false;
				break;
			}
			maxClaims = min(maxClaims, freq[types[i]]);// this is the max we can claim this prize
		}
		if (possiblePrize) {
			res += tmpCash * maxClaims;
			for (int i = 0; i < N; i ++) {
				freq[types[i]] -= maxClaims;
			}
		}


		prizes.pop();
	}
	printf("%d\n", res);
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

