
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

bool isValidMove(char (&grid)[8][8], char move, ii& pos, int& direction) {
	if (move == 'R') {
		direction -= 90;
		if (direction < 0) direction = 270;
		return true;
	}
	if (move == 'L') {
		direction += 90;
		if (direction > 270) direction = 0;
		return true;
	}
	// 0 -> i j + 1
	// 90 -> i-1 j
	// 180 -> i j - 1
	// 270 -> i + 1 j

	ii target;
	if (direction == 0) target = make_pair(pos.first, pos.second + 1);
	else if (direction == 90) target = make_pair(pos.first - 1, pos. second);
	else if (direction == 180) target = make_pair(pos.first, pos.second - 1);
	else if (direction == 270) target = make_pair(pos.first + 1, pos.second);

	if (target.first > 7 || target.second > 7 || target.first < 0 || target.second < 0) return false;
	if (move == 'X') {
		if (grid[target.first][target.second] == 'I') {
			grid[target.first][target.second] = '.';
			return true;
		}
		return false;
	}
	else if (move == 'F') {
		if (grid[target.first][target.second] == '.') {
			grid[target.first][target.second] = 'T';
			grid[pos.first][pos.second] = '.';
			pos = target;
			return true;
		}
		else if (grid[target.first][target.second] == 'D') {
			grid[pos.first][pos.second] = '.';
			pos = target;
			return true;
		}
		return false;
	}
	return false;

}

void solve() {
	string line;
	char grid[8][8];
	for (int i = 0; i < 8; i ++) {
		getline(cin, line);
		for (int j = 0; j < 8; j ++) {
			grid[i][j] = line[j];
		}
	}
	getline(cin, line);
	ii pos = make_pair(7, 0);
	string res = "";
	int n = line.length();
	int direction = 0;
	for (int i = 0; i < n; i ++) {
		if (! isValidMove(grid, line[i], pos, direction)) {
			res = "Bug!";
			break;
		}
	}
	if (res == "" && grid[pos.first][pos.second] == 'D') res = "Diamond!";
	else res = "Bug!";
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

