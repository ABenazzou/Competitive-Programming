
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
	int cess[3], ce[2];
	while (scanf("%d %d %d %d %d", &cess[0], &cess[1], &cess[2], &ce[0], &ce[1]) && (ce[0] || ce[1] || cess[0] || cess[1] || cess[2])) {
		sort(cess, cess + 3);
		// he needs 3 cards > mid
		// or 2 cards > max
		if (ce[0] > cess[2] && ce[1] > cess[2]) {
			// lowest card bcz he always wins
			for (int i = 1; i <= 52; i ++) {
				if (i != ce[0] && i != ce[1] && i != cess[0] && i != cess[1] && i != cess[2]) {
					// first small int
					printf("%d\n", i);
					break;
				}
			}
		}
		else if (ce[0] < cess[1] || ce[1] < cess[1]) {// if 1 of the cards < mid we need to guarantee 2 > max
			if (ce[0] > cess[2] || ce[1] > cess[2]) {
				bool found = false;
				for (int i = cess[2] + 1; i <= 52; i ++){
					if (i != ce[0] && i != ce[1]) {
						found = true;
						printf("%d\n", i);
						break;
					}
				}
				// if we cant guarantee 3 > mid nor 2 > max, no win guaranteed
			if (!found) printf("-1\n");

			} else {
				// we cant guarantee 2 cards > max
				printf("-1\n");
			}
		}
		else {
			// we need to guarantee 3 > mid
			bool sfound = false;
			for (int i = cess[1] + 1; i <= 52; i ++) {
				if (i != ce[0] && i != ce[1] && i != cess[2]) {
					printf("%d\n", i);
					sfound = true;
					break;
				}
			}
			if (!sfound) printf("-1\n");
		}
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

