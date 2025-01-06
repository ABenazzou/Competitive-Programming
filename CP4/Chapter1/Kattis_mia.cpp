/*
 * Created: 2025-01-06
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

bool comp(int a, int b) {
	return a > b;
}

void solve() {
	// getline(cin, s);
	int s[2], r[2];
	while (scanf("%d %d %d %d", &s[0], &s[1], &r[0], &r[1]) && (s[0] || s[1] || r[0] || r[1])) {
		sort(s, s + 2, comp);
		sort(r, r + 2, comp);
		int win = 0;
		if (s[0] == r[0] && s[1] == r[1]) {
			printf("Tie.\n");
			continue;
		} else if ((s[0] == 2 && s[1] == 1)) {
			win = 1;
		} else if ((r[0] == 2 && r[1] == 1) ) {
			win = 2;
		} else if  (s[0] == s[1]) {
			if (r[0] == r[1] && s[0] > r[0]) {
				win = 1;
			}
			else if (r[0] == r[1] && s[0] < r[0]) {
				win = 2;
			}
			else if (r[0] != r[1]) {
				win = 1;
			}
		} else if (r[0] == r[1]) {
			win = 2;
		}
		else {
			int p1 = stoi(to_string(s[0]) + to_string(s[1]));
			int p2 = stoi(to_string(r[0]) + to_string(r[1]));
			if (p1 > p2) {
				win = 1;
			} else {
				win = 2;

			}
		}
		
		printf("Player %d wins.\n", win);	
	}
}


int main() {
	//ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}
