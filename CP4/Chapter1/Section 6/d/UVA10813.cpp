
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

bool isWinning(vector<vi> card, int x, int y) {

    // current col 
    for (int i = 1; i < 5; i ++) {
        if (card[(x + i) % 5][y] != - 1) break;
        if (i == 4) return true;
    }
    // current line 
    for (int i = 1; i < 5; i ++) {
        if (card[x][(y + i) % 5] != - 1) break;
        if (i == 4) return true;
    }
    // diagonal and antidiagonal
    for (int i = 0; i < 5; i ++) {
	    if (card[i][4 - i] != - 1) break;
	    if (i == 4) return true;
    }
    for (int i = 0; i < 5; i ++) {
	    if (card[i][i] != - 1) break;
	    if (i == 4) return true;
    }
    return false;
}

void solve() {
    map<int, ii> idxs;
    vector<vi> card(5, vi(5));
    int res = -1;
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (i == 2 && j == 2) {
                card[i][j] = -1;
            }
            else {
                cin >> card[i][j];
                idxs[card[i][j]] = make_pair(i, j);
            }
        }
    }
    cin.ignore();
    bool isOver = false, isWon = false;
    int idx = 0, tmp;
    string line;
    while (!isOver) {
        getline(cin, line);
        istringstream iss(line);
        while(iss >> tmp) {
            if (idxs.find(tmp) != idxs.end()) {
                int x = idxs[tmp].first, y = idxs[tmp].second;
                card[x][y] = - 1;
                // check if conditions met
                // check line = +1 +2 +3 +4
                if (!isWon && isWinning(card, x, y)){
			res = idx + 1;
                        isWon = true;
                }
            } 
            idx ++;
        }
        if(idx == 75) isOver = true;
    }
     
    cout << "BINGO after " << res << " numbers announced\n";
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

