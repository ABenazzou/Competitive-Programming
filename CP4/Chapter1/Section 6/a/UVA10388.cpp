
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
	string dummy;
	getline(cin, dummy);
	deque<char> pileJane, pileJohn;
	string jane, john;// top to bottom
	cin >> jane >> john;
	cin.ignore();
	dbg(jane, john);
	// start with same num cards < 50 each
	// time to call Snap -> random determins who calls first 0 = Jane, otherwise John
	for (int i = 0; jane[i]; i ++) {
		pileJane.emplace_front(jane[i]);
		pileJohn.emplace_front(john[i]);
	}
	char tmp;

	deque<char> janeSide, johnSide;
	for (int i = 0; i < 1000; i++) {
		char janeC = pileJane.back();
		pileJane.pop_back();
		char johnC = pileJohn.back();
		pileJohn.pop_back();
		if (janeC != johnC) {
			janeSide.emplace_back(janeC);
			johnSide.emplace_back(johnC);
			dbg(janeSide, johnSide, pileJane, pileJohn);
		} else {
			int winner = random()/141%2;
			if (winner == 0) {
				dbg(johnSide);
				janeSide.emplace_back(janeC);
				while(!johnSide.empty()) {
					tmp = johnSide.front();
					johnSide.pop_front();
					janeSide.emplace_back(tmp);

				}
				janeSide.emplace_back(johnC);
				dbg(janeSide);
				cout << "Snap! for Jane: " ; 
				for(int j = janeSide.size() - 1; j >= 0; j --){
					cout << janeSide[j];
				}
				cout << '\n';
			} else {
				johnSide.emplace_back(johnC);
				while(!janeSide.empty()) {
					tmp = janeSide.front();
					janeSide.pop_front();
					johnSide.emplace_back(tmp);

				}
				johnSide.emplace_back(janeC);
				cout << "Snap! for John: " ;
				for (int j = johnSide.size() - 1; j >= 0; j --){
					cout << johnSide[j];	

				}
				cout << '\n';
			}
		}

		// if empty - > winner, else shuffle
		if ((janeSide.empty() && pileJane.empty())) {
			cout << "John wins.\n";
			return ;
		} else if ((johnSide.empty() && pileJohn.empty())) {
			cout << "Jane wins.\n";
			return;
		} else if (pileJohn.empty() || pileJane.empty()){
			dbg(pileJohn, pileJane);
			dbg(johnSide, janeSide);
			if (pileJohn.empty()) {
				while (!johnSide.empty()) {
					tmp = johnSide.back();
					johnSide.pop_back();
					pileJohn.emplace_back(tmp);// A B C - > C B A
				}

			}
			if (pileJane.empty()) {

				while (!janeSide.empty()) {
					tmp = janeSide.back();
					janeSide.pop_back();
					pileJane.emplace_back(tmp);
				}

			}
			dbg(pileJohn, pileJane);
			dbg(johnSide, janeSide);

		} 

	}
	cout << "Keeps going and going ...\n\n" << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    //scanf("%d", &tc);
    
    cin.ignore();
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

