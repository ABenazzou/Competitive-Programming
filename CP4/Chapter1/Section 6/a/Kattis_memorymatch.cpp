
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
	
	int n, k;
	cin >> n >> k;
	int c1, c2;
	string p1, p2;
	set<string> visited, pairs;
	set<int> visitedPosition;
	int scoredP1 = 0, scoredP2 = 0;
	bool isPlayer1 = true;
	for (int i = 0; i < k; i ++) {
		cin >> c1 >> c2 >> p1 >> p2;
		// we do not care abt card position
		if (p1 == p2) {
			if (isPlayer1) {
				scoredP1 ++;
			} else {
				scoredP2 ++;
			}
			// if they are the same they do not contribute to score
			if (pairs.find(p1) != pairs.end()) {
				pairs.erase(p1);
			}
		} else {
			//switch turns at the end
			if (visited.find(p1) != visited.end() && visitedPosition.find(c1) == visitedPosition.end()) {
				// pair if we visited it and it has a different number
				// than the visited one
				pairs.insert(p1);
			} 
			if (visited.find(p2) != visited.end() && visitedPosition.find(c2) == visitedPosition.end()) {
				pairs.insert(p2);
			}
			// if we knew p1/p2 and the new position is not known, add pair

			isPlayer1 = !isPlayer1;
		}
		// mark as visited
		visited.insert(p1);
		visited.insert(p2);
		visitedPosition.insert(c1);
		visitedPosition.insert(c2);


	}
		// this is the guaranteed score
	
	int playerScore = isPlayer1? scoredP1 : scoredP2, oppositeScore = isPlayer1? scoredP2 : scoredP1, visN = visited.size(), visPN = visitedPosition.size(), res;
	
	if ((visN == (n / 2)) || (visN == ((n / 2) - 1) && (visPN == (n - 2)))) {
	// edge case: we flipped n/2 unique cards -> we know all positions
	// we finish the game so our score is total - opponent - ours bcz we want to know current round score only
		dbg(visN, visPN);
		res = (n / 2) - oppositeScore - playerScore;

	// edge case2: we flipped n/2 - 1 unique cards and cards down = 2 -> we know all positions bcz last pair is unknown
	// we finish the game again, score = total - opponent
	}
	else {
		// we cant finish the game so we can only score what we have
		res = pairs.size(); // pairs that we didnt use
	}
	cout << res << '\n';
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

