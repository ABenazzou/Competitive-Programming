
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

bool didWin(char grid[3][3], char player) {
	bool won[4];
	won[2] = won[3] = true;
	for (int i = 0; i < 3; i ++){
		won[0] = grid[i][0] == player;
		won[0] &= (grid[i][1] == player);
		won[0] &= (grid[i][2] == player);
		if (won[0]) break;

		won[1] = grid[0][i] == player;
		won[1] &= (grid[1][i] == player);
		won[1] &= (grid[2][i] == player);
		if(won[1]) break;

		won[2] &= grid[i][i] == player;
		won[3] &= grid[i][2 - i] == player;
	}
	return (won[0] || won[1] || won[2] || won[3]);
}

void solve() {
	char grid[3][3];
	string tmp;
	int cntX = 0, cntO = 0;
	for (int i = 0; i < 3; i ++) {
		getline(cin, tmp);
		for (int j = 0; j < 3; j ++) {
			grid[i][j] = tmp[j];
			if (tmp[j] == 'X') cntX++;
			else if (tmp[j] == 'O') cntO++;
		}
	}
	string res = "";
	bool wonX = didWin(grid, 'X'), wonO = didWin(grid, 'O');
	if ((wonX && wonO) || ((cntX - cntO) != 1 && cntX != cntO) ) {
		res = "no";
	}
	else if (cntX == cntO) {
		// either O won or neither won or no
		res = (wonO || !wonX) ? "yes" : "no";
		
	} else if (cntX == cntO + 1) {
		// either X won or neither won no
		res = (wonX || !wonO) ? "yes" : "no";
	}
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    cin.ignore();
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
		string fodder;
		if (i != tc) getline(cin, fodder);
	}

	return 0;
}

