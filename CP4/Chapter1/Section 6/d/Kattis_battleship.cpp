
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

void solve() {
	int w, h, n;
	cin >> w >> h >> n;
	cin.ignore();
	string line;
	set<int> deployp1, deployp2;
	for (int i = 0; i < 2 * h; i ++) {
		// p1 states
		getline(cin, line);
		for (int j = 0; j < w; j ++) {
			if (line[j] == '#') (i < h) ? deployp1.insert(i * w + j) : deployp2.insert((i - h) * w + j);
		}
	}
	int x, y;
	bool isTurnOver = false, isPlayer1 = true;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y;
		if ((deployp1.size() == 0 || deployp2.size() == 0) && isTurnOver) continue;
		int tmp = (h - 1 - y) * w + x;

		if (isPlayer1)  {
			// if player 1 plays turn not over
			isTurnOver = false;
			if (deployp2.find(tmp) != deployp2.end()) {
				deployp2.erase(tmp);
			} else {
				// miss = p2 plays
				isPlayer1 = false;
			}
			// all ships destroyed, p2 still gets to play
			if (deployp2.size() == 0) isPlayer1 = false;
		} else {
			if (deployp1.find(tmp) != deployp1.end()) {
				deployp1.erase(tmp);
			} else {
				// if player 2 fails turn over
				isPlayer1 = true;
				isTurnOver = true;
			}

		}
	}
	dbg(deployp1, deployp2);
	if (deployp1.size() == 0 && deployp2.size() == 0) cout << "draw\n";
	else if (deployp1.size() == 0) cout << "player two wins\n";
	else if (deployp2.size() == 0) cout << "player one wins\n";
	else cout << "draw\n";

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

