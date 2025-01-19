
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
	int n, k;
	scanf("%d %d", &n, &k);
	int x[n];
	map<int, int> freq;
	set<int> hasComplement;
	for (int i = 0; i < n; i ++) {
		scanf("%d", &x[i]);
		if (freq.find(x[i]) == freq.end()) freq[x[i]] = 0;
		freq[x[i]] ++;
		if (freq.find(k - x[i]) != freq.end()) {
			hasComplement.insert(x[i]);
			hasComplement.insert(k - x[i]);
		}
	}
	dbg(freq);
	/*
	int skipTurns = 0;
	for (auto it = noComplement.begin(); it != noComplement.end(); it ++) {
		// she will always play it, bob as well as long as possible
		skipTurns += freq[*it];
	}
	*/
	int score = 0;
	// if skip turns is %2 == 1 then others are %2 == 1 too bcz n pair so he always can sack smthng
//	if (skipTurns % 2 == 0) { // if bob can counter all of alice picks then alice is forced to give him the score
		for (auto it = hasComplement.begin(); it != hasComplement.end(); it ++) {
			int tmp = min(freq[*it], freq[k - *it]);
			if (*it == k - *it) {
				tmp /= 2;
			}
			score += tmp;
			freq[*it] -= tmp;
			freq[k - *it] -= tmp;
		}
//	} 	
	printf("%d\n", score);

	// max score is n/2 i.e all complements turns
	// alice will choose no compl and bob too if possible; score will not change for noCompl.size()/2 ceil
//	int score = (n / 2) - ceil(1.0 * noComplement.size() / 2 );
	
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    //cin >> tc;
    scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve();
	}

	return 0;
}

