/*
 * Created: 2024-12-27
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


double getDistance(ii s1, ii s2) {
	int x = s1.first - s2.first;
	int y = s1.second - s2.second;
	x *= x;
	y *= y;
	
	return sqrt(x + y);
}

double backtrack(vector<ii>& students, int n, int mask, map<int, double>& memo) {
	// improvement? Memoize partial states and add them if they are found subsequently
    // If all students are paired (mask has all bits set), return 0 (no more distance to add)
    if (mask == (1 << (2 * n)) - 1) {
        return 0.0;
    }

    // If this state has been computed before, return the memoized result
    if (memo.count(mask)) {
        return memo[mask];
    }

    double minDist = 1e9; // A large number, represents the minimum distance found

    // Try pairing every unpaired student
    for (int i = 0; i < 2 * n; i++) {
        // If student i is already paired (bit i is set in mask), skip it
        if (mask & (1 << i)) continue;

        // Try pairing student i with every other unpaired student j
        for (int j = i + 1; j < 2 * n; j++) {
            // If student j is already paired, skip it
            if (mask & (1 << j)) continue;

            // Calculate the distance between student i and student j
            double dist = getDistance(students[i], students[j]);

            // Recurse with the new mask where i and j are paired
            double newDist = dist + backtrack(students, n, mask | (1 << i) | (1 << j), memo);
            minDist = min(minDist, newDist);
        }
    }

    // Memoize the result for this state
    memo[mask] = minDist;
    return minDist;
}

void solve() {
    int N;
    while (cin >> N && N) {
        vector<ii> students(2 * N);
        for (int i = 0; i < 2 * N; i++) {
            string name;
            int x, y;
            cin >> name >> x >> y;
            students[i] = {x, y};
        }

        // Memoization map: key is the mask (bitmask of visited students), value is the minimum distance
        map<int, double> memo;
        double result = backtrack(students, N, 0, memo);
        cout << fixed << setprecision(2) << result << '\n';
    }
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}
