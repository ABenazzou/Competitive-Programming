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


void solve() {
	// getline(cin, s);
	map<char, int> loveScore;
	int start = int('a');
	for (int i = 1; i < 27; i ++){
		char letter = char(start + i - 1);
		loveScore[letter] = i;
	} 
	dbg(loveScore);
	string s1;
	string s2;
	while(getline(cin, s1) && getline(cin, s2)) {
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		int n = s1.length();
		int m = s2.length();
		
		int res1 = 0, res2 = 0;
		for (int i = 0; i < n; i ++){
			if (loveScore.find(s1[i]) != loveScore.end()) {
				res1 += loveScore[s1[i]];
			}
		}
		
		for (int i = 0; i < m; i ++){
			if (loveScore.find(s2[i]) != loveScore.end()) {
				res2 += loveScore[s2[i]];
			}
		}
		// clever sol
		int a = (res1 % 9)? res1 % 9 : 9;
		int b = (res2 % 9)? res2 % 9 : 9;
		float res = (a > b)? 100.0 * b / a : 100.0 * a / b;
		cout << fixed << setprecision(2) << res << " %\n"; 
		/*
		
		// iterate till one digit
		s1 = to_string(res1);
		s2 = to_string(res2);
		n = s1.length();
		m = s2.length();
		while (n != 1) {
			//dbg(n);
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += s1[i] - '0';
			}
			s1 = to_string(tmp);
			n = s1.length();

		}
		
		while (m != 1) {
			//dbg(m);
			int tmp = 0;
			for (int i = 0; i < m; i++) {
				tmp += s2[i] - '0';
			}
			s2 = to_string(tmp);
			m = s2.length();

		}
		
		//dbg(s1, s2);
		int a = stoi(s1);
		int b = stoi(s2);
		float res = (a > b)? 100.0 * b / a : 100.0 * a / b;
		cout << fixed << setprecision(2) << res << " %\n"; 
		*/
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
