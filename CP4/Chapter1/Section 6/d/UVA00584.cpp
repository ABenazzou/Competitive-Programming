
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

void solve() {
	string s;
	while (getline(cin, s) && s != "Game Over") {
		int prev, score = 0;
		istringstream iss(s);
		vi scores;
		set<int> strikes, spares;
		char tmp;
		int round = 1, roll = 1, lastRollIdx = INF;
		while (iss >> tmp) {
			if (round == 10) {
				lastRollIdx = scores.size();
			}
			if (tmp == 'X') {
				scores.push_back(10);
				strikes.insert(scores.size() - 1);
				round ++;
			} else if (tmp == '/') {
				scores.push_back(10 - prev);
				spares.insert(scores.size() - 1);
				round ++;
				roll = 1;
			} else {
				prev = tmp - '0',
				scores.push_back(prev);
				if (roll == 2) {
					round ++;
					roll = 1;
				} else {
					roll ++;
				}
			}
		}
		int n = scores.size();
		for (int i = 0; i < n; i ++) {
			// last round score: first throw X + next 2 throws
			// second throw / + next 1 throw
			// 2 throws
			if (i >= lastRollIdx) {
				score += scores[i]; // score for round 10 be it 2 or 3 throws 
			}
			else if ((strikes.find(i) != strikes.end())) {
				score += scores[i] + scores[i + 1] + scores[i + 2];
			}
			else if ((strikes.find(i) != strikes.end()  || spares.find(i) != spares.end())) {
				score += scores[i] + scores[i + 1];
			} else {
				score += scores[i];
			}
		}
		cout << score << '\n';
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

