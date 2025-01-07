/*
 * Created: 2025-01-07
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
	// getline(cin, s);
	int n;
	char p;
	string res;
	map<char, pair<bool, int>> scores;
	while (cin >> n && (n != -1)) {
		cin >> p >> res;
		if (scores.find(p) == scores.end()) {
			scores[p] = make_pair(false, 0);
		}
		
		if (scores[p].first) {
			continue;
		}
		
		if(res == "wrong") {
			scores[p].second += 20;
		} else if (res == "right") {
			scores[p].first = true;
			scores[p].second += n;
		}
	}
	
	int score = 0;
	int problems = 0;
	for (map<char, pair<bool, int>>::iterator it = scores.begin(); it != scores.end(); ++ it) {
		if (it -> second.first) {
			score += it -> second.second;
			problems ++;
		}
	}
	cout << problems << " " << score << '\n';
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
