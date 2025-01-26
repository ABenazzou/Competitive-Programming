
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

bool isLegalState(int k, int q) {
	return k != q;
}

bool isLegalMove(int k, int q, int newQ) {
	if (k == newQ || newQ == q) return false;
	int kC = k % 8, qC = q % 8, kR = k / 8, qR = q / 8;

	if (qC != newQ % 8 && qR != newQ / 8 ) {
		// not same row nor same column
		return false;
	}
	// invalid if not same row /col
	// invalid only if equal row/col and queen went beyond it
	if ((kR == qR && kR == (newQ / 8)) || (kC == qC && kC == (newQ % 8))) {
		// same col
		if (k > q && k < newQ) {
			return false; // went over k
		}
		else if (k < q && k > newQ ) {
			return false;
		}
	}
	return true;
}

bool isAllowedMove(int k, int newQ) {
	// move already llegal but is it allowed?
	// queen should not be within +- 1 of the king hor or ver
	int kC = k % 8, kR = k / 8;
	int kingPeripheral[4] = {kC - 1, kC + 1, kR - 1, kR + 1};
	int kingPositions[4] = {k - 1, k + 1, k - 8, k + 8};
	for (int i = 0; i < 4; i ++) {
		if (kingPeripheral[i] >= 0 && kingPeripheral[i] < 8) {
			// check if queen not within the range
			if (newQ == kingPositions[i]) {
				return false;
			}
		}
	}
	return true;

}

bool isGameOver(int k, int newQ) {
	// game over if king positions taken by queen
	
	int kC = k % 8, kR = k / 8, qC = newQ % 8, qR = newQ / 8;
	int kingPeripheral[4] = {kC - 1, kC + 1, kR - 1, kR + 1};
	int kingPositions[4] = {k - 1, k + 1, k - 8, k + 8};
	for (int i = 0; i < 4; i ++) {
		if (kingPeripheral[i] >= 0 && kingPeripheral[i] < 8 && newQ != kingPositions[i]) {
			// check if any move is not in queen range
			// 1 & 2 -> kR, peripheral, 3 & 4 -> qC, peripheral
			if (i == 0 || i == 1) {
				if (kR != qR && kingPeripheral[i] != qC) {
					return false;
				}
			}
			else {
				if (kingPeripheral[i] != qR && kC != qC) {
					return false;
				}
			}
		}
	}
	return true;
}

void solve() {
	int k, q, newQ;
	while (scanf("%d %d %d", &k, &q, &newQ) != EOF) {
		if (!isLegalState(k, q)) {
			printf("Illegal state\n");
			continue;
		}
		if (!isLegalMove(k, q, newQ)) {
			printf("Illegal move\n");
			continue;
		}
		if (!isAllowedMove(k, newQ)) {
			printf("Move not allowed\n");
			continue;
		}
		if (!isGameOver(k, newQ)) {
			printf("Continue\n");
			continue;
		}
		printf("Stop\n");
	}
}


int main() {
//	ios_base::sync_with_stdio(0);
 //   cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

