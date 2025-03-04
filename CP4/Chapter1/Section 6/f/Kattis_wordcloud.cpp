
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

void solve() {
	int W, n, tc = 1;
	while (cin >> W >> n && (W || n)) {
		vii words;
		int cmax = EPS;
		for (int i = 0; i < n; i ++) {
			string s;
			int c;
			cin >> s >> c;
			cmax = max(cmax, c);
			words.push_back(make_pair(s.length(), c));
		}


		dbg(words);
		int resL = 0, resW = 0, lineL = 0;
		for (int i = 0; i < n; i ++) {
			int cw = words[i].second, t = words[i].first;
			int p = 8 + ceil((40.0 * (cw - 4)) / (cmax - 4));
			int w = ceil((9.0 * t * p)/16.0);
			dbg(resW, w, W);
			// 10 pt between words
			// after inserting any word add 10 pt
			if (resW + w <= W) {
				resW += w + 10;// if the word fits add it and add space. if space is beyond W, should go in the else either way
				// add W and store maxL of line
				lineL = max(lineL, p);
			}
			else {
				//jump line -> reset W to curr word
				resW = w + 10;
				// set p of previous line and update currentLine
				resL += lineL;
				lineL = p;
			}
		}
		// add results of last line
		resL += lineL;
		cout << "CLOUD " << tc ++ << ": " << resL << '\n';
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

