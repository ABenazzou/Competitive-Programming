
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

int readBoard(string FEN, char (&board)[64]){
	int n = FEN.size();
	int j = 0;
	for (int i = 0; i < n; i ++) {
		if (isdigit(FEN[i])) {
			for (int k = 0; k < (FEN[i] - '0'); k ++) {
				board[j] = '.';
				j ++;
				// empty square
			}
		}
		else if (FEN[i] == '/') {
			continue;
		} else if (isalpha(FEN[i])){
			board[j] = FEN[i];
			j ++;
		}
	}
	return j;
}

void displayBoard(char board[]){
	// debug
	cout << "-----------BOARD------------" << '\n';
	for (int i = 0; i < 64; i ++) {
		if ((i % 8) == 0) cout << '\n';
		cout << " | " << board[i];
	}
	cout << "\n---------------------------" << '\n';
}

void checkHorizontally(char (&board)[64], int pos, int row) {
	for (int tmp = pos - 1; tmp >= (row * 8); tmp --) {
		if (board[tmp] != '.' && board[tmp] != 'A') break;
		// same row and not full
		board[tmp] = 'A';
	}
	for (int tmp = pos + 1; tmp < ((row + 1) * 8); tmp ++) {
		if (board[tmp] != '.' && board[tmp] != 'A') break;
		// same row and not full
		board[tmp] = 'A';

	}
}

void checkVertically(char (&board)[64], int pos) {
	for (int tmp = pos - 8; tmp >= 0; tmp -= 8) {
		if (board[tmp] != '.' && board[tmp] != 'A') break;
		// same col and not full
		board[tmp] = 'A';
	}
	for (int tmp = pos + 8; tmp < 64; tmp += 8) {
		if (board[tmp] != '.' && board[tmp] != 'A') break;
		// same col and not full
		board[tmp] = 'A';

	}
}


void checkDiagonally(char (&board)[64], int pos) {
	if ((pos + 1) % 8 != 0) {
		// if its edge no right diagonal
		for (int tmp = pos - 7; tmp >= 0; tmp -= 7) {
			if (board[tmp] != '.' && board[tmp] != 'A') break;
			// this direction / -> edge row breaks
			board[tmp] = 'A';
			if ((tmp + 1) % 8 == 0) break;
		}
		for (int tmp = pos + 9; tmp < 64; tmp += 9) {
			if (board[tmp] != '.' && board[tmp] != 'A') break;
			board[tmp] = 'A';
			// this direction \ -> edge row breaks
			if ((tmp + 1) % 8 == 0) break;
		}
	}
	if (pos % 8 != 0) {
		// if start, no left diagonal
		for (int tmp = pos - 9; tmp >= 0; tmp -= 9) {
			if (board[tmp] != '.' && board[tmp] != 'A') break;
			board[tmp] = 'A';
			if (tmp  % 8 == 0) break;
		}
		for (int tmp = pos + 7; tmp < 64; tmp += 7) {
			if (board[tmp] != '.' && board[tmp] != 'A') break;
			board[tmp] = 'A';
			if (tmp % 8 == 0) break;
		}
	}
}

void fillAttackedCells(char (&board)[64]) {
	vi moves;
	bool checkMoves = false;
	for (int i = 0; i < 64; i ++) {
		moves.clear();
		if (board[i] == '.' || board[i] == 'A') continue; 

		// pawn
		if (tolower(board[i]) == 'p') {
			char attacker = (isupper(board[i]))? 'W' : 'B';
			// if attacker is black check + 7 and + 9
			// if attacker is white check - 7 and -9
			if (attacker == 'B') {
				if (i % 8 != 0) moves.push_back(7);
				if ((i + 1) % 8 != 0) moves.push_back(9);
			}
			else {
				if (i % 8 != 0) moves.push_back(-9);
				if ((i + 1) % 8 != 0) moves.push_back(-7);
			}
			checkMoves = true;
		}
		// knight
		else if (tolower(board[i]) == 'n') {
			// we dont care if its white or b
			// we only need to check if its not in the far edges where knight cant move
			if (i % 8 != 0) {
				moves.push_back(-17);
				moves.push_back(15);
				if ((i - 1) % 8 != 0) {
					moves.push_back(-10);
					moves.push_back(6);
				}
			}
			if ((i + 1) % 8 != 0) {
				moves.push_back(-15);
				moves.push_back(17);
				if ((i + 2) % 8 != 0) {
					moves.push_back(-6);
					moves.push_back(10);
				}
			}
			checkMoves = true;
		} 
		// king
		else if (tolower(board[i]) == 'k') {
			// we dont care white or black
			if (i % 8 != 0) {
				moves.push_back(-9);
				moves.push_back(-1);
				moves.push_back(7);
			}
			if ((i + 1) % 8 != 0) {
				moves.push_back(-7);
				moves.push_back(1);
				moves.push_back(9);
			}
			moves.push_back(-8);
			moves.push_back(8);
			checkMoves = true;
		}
		// rook
		else if (tolower(board[i]) == 'r') {
			// moves are valid until something in the way e.g not . or A
			checkMoves = false;
			int row = i / 8;
			checkHorizontally(board, i, row);
			checkVertically(board, i);
		}
		// bishop
		else if (tolower(board[i]) == 'b') {
			checkMoves = false;
			checkDiagonally(board, i);
		}
		// queen
		else if (tolower(board[i]) == 'q') {
			checkMoves = false;
			int row = i / 8;
			checkHorizontally(board, i, row);
			checkVertically(board, i);
			checkDiagonally(board, i);
		}

		if (!checkMoves) continue;
		for (int move: moves) {
			int cell = i + move;
			if (cell < 0 || cell >= 64) continue;
			if (board[cell] == '.') {
				board[cell] = 'A';
			}
		}
	}
}

void solve() {
	string FEN;
	while(getline(cin, FEN)) {
		char board[64];
		dbg("TestCase --------------------\n");
		int boardSize = readBoard(FEN, board);
		//displayBoard(board);
		fillAttackedCells(board); // 'W' attacked by white, 'B' attacked by black;
					  // we dont care if its attacked by both;
					  // we dont care who attacks, just mark as 'A'
		//displayBoard(board);
		cout << count(board, board + boardSize, '.') << '\n'; 
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

