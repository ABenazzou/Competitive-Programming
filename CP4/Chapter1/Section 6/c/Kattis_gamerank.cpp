
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
	int maxStars[26];
	for (int i = 1; i < 11; i ++) {
		maxStars[i] = 5;
	}
	for (int i = 11; i < 16; i ++) {
		maxStars[i] = 4;
	}
	for (int i = 16; i < 21; i ++) {
		maxStars[i] = 3;
	}
	for (int i = 21; i < 26; i ++) {
		maxStars[i] = 2;
	}

	int rank = 25, stars = 0;
	string history;
	cin >> history;
	int consecutiveWins = 0;
	for (char gameResult: history) {
		if (gameResult == 'L') {
			consecutiveWins = 0;
			if (rank > 20) {
				continue;
			} else if (rank == 20) {
				stars = max(stars - 1, 0);
			} else {
				stars --;
				if (stars < 0) {
					rank ++; 
					stars = maxStars[rank] - 1;
				}
			}
			
		}
		else {
			consecutiveWins ++;
			stars ++;
			if (rank > 5 && consecutiveWins >= 3) {
				stars ++;
			}

			if (stars > maxStars[rank]) {
				stars = stars - maxStars[rank];
				rank --; 
				if (rank < 1) break;
			}
		}
	}
	if (rank < 1) {
		cout << "Legend\n";
	} else {
		cout << rank << '\n';
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

