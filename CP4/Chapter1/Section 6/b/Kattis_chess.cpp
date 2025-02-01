
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


int checkIntersection(char board[64], int iPos) {
	if (board[iPos] == 'E') {
		return iPos;
	}
	else if(board[iPos] == 'A') {
		board[iPos] = 'D';// double
		return iPos;
	}
	return -1;
}

int checkDiagonally(char (&board)[64], int pos) {
	int res;
	if ((pos + 1) % 8 != 0) {
		// if its edge no right diagonal
		for (int tmp = pos - 7; tmp >= 0; tmp -= 7) {
			assert(tmp >= 0 && tmp < 64);
			// empty board
//			if (board[tmp] != '.' && board[tmp] != 'A') break;
			// this direction / -> edge row breaks
			res = checkIntersection(board, tmp);
			if (res != -1) return res;
			board[tmp] = 'A';
			if ((tmp + 1) % 8 == 0) break;
		}
		for (int tmp = pos + 9; tmp < 64; tmp += 9) {
			assert(tmp >= 0 && tmp < 64);
			res = checkIntersection(board, tmp);
			if (res != -1) return res;

			board[tmp] = 'A';
			// this direction \ -> edge row breaks
			if ((tmp + 1) % 8 == 0) break;
		}
	}
	if (pos % 8 != 0) {
		// if start, no left diagonal
		for (int tmp = pos - 9; tmp >= 0; tmp -= 9) {
			assert(tmp >= 0 && tmp < 64);
			res = checkIntersection(board, tmp);
			if (res != -1) return res;

			board[tmp] = 'A';
			if (tmp  % 8 == 0) break;
		}
		for (int tmp = pos + 7; tmp < 64; tmp += 7) {

			assert(tmp >= 0 && tmp < 64);
			res = checkIntersection(board, tmp);
			if (res != -1) return res;
			board[tmp] = 'A';
			if (tmp % 8 == 0) break;
		}
	}
	// no end no intersection
	return -1;
}

void solve() {
	char cColStart, cColEnd;
	int rowStart, rowEnd, colStart, colEnd;
	char board[64];
	for (int i = 0; i < 64; i ++) {
		board[i] = '.';
	}
	cin >> cColStart >> rowStart >> cColEnd >> rowEnd;
	if (cColStart == cColEnd && rowStart == rowEnd) {
		cout << "0 " << cColEnd << " " << rowEnd << '\n';
		return;
	}
	colStart = cColStart - 'A';
	colEnd = cColEnd - 'A';
	rowStart --;
	rowEnd --;

	bool isReachable = ((colStart % 2) == (rowStart % 2)) == ((colEnd % 2) == (rowEnd % 2));
	if (!isReachable) {
		cout << "Impossible\n";
		return;
	}
	// everything is 0 baseed now
	int cellStart = rowStart * 8 + colStart, cellEnd = rowEnd * 8 + colEnd;
	board[cellStart] = 'S';
	board[cellEnd] = 'E';

	int checkDiagonal = checkDiagonally(board, cellStart);
	if (checkDiagonal != -1) {
		// end pos found
		cout << "1 " << cColStart << " " << rowStart + 1 << " " << cColEnd << " " << rowEnd + 1 << '\n';
		return;
	}
	checkDiagonal = checkDiagonally(board, cellEnd);
	// we re sure it ll hit this tim
	int row = checkDiagonal / 8;
	row ++;
	char col = checkDiagonal % 8 + 'A';
	cout << "2 " << cColStart << " " << rowStart + 1 << " " << col << " " << row << " " << cColEnd << " " << rowEnd + 1 << '\n'; 

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

