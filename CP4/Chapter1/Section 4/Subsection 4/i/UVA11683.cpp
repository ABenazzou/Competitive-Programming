/*
 * Created: 2025-01-10
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
	// getline(cin, s);
	int H, L;
	while (scanf("%d %d", &H, &L) && ( H || L)) {
		int X[L];
		for (int i = 0; i < L; i ++) {
			scanf("%d", &X[i]);
			//X[i] = H - X[i];
		}
		
		// O(N)
		int operations = H - X[0]; // drills needed at 0
		int currentDrills;
		for (int i = 1; i < L; i ++) {
			currentDrills = H - X[i];
			if (currentDrills <= 0) {
				continue; // nothing to drill here
			}
			if (X[i] < X[i - 1]) {
				// current level needs more drills than prev
				operations += X[i - 1] - X[i]; // drills whats left
			}
		}
		printf("%d\n", operations);
		// O (N 2) TLE
		//bool isLaserOn;
		//int operations = 0;
		//for (int j = 1; j <= H; j ++) {
			//isLaserOn = false;
			//int tmpOperations = 0;
			//tmp = H - j; // Assume we drill the level;
			//for (int i = 0; i < L; i ++) {
				//if (tmp >= X[i] && !isLaserOn) {
					 //need to dig;
					 //turn On Laser
					//dbg(j, i);
					//tmpOperations ++;
					//isLaserOn = true;
				//} else if (tmp < X[i]){
					 //turn off laser
					//isLaserOn = false;
					 //do not turn on unless need to dig
				//}
			//}
			//operations += tmpOperations;
		//}
		//printf("%d\n", operations);
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
