
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


void solve(int tc) {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int n = s.size();
	stack<int> question0, question1, mismatch0, mismatch1;// mismatchi means t string has i
	int res = 0;
	if (s == t) {
		cout << "Case " << tc << ": " <<res << '\n';
		return;
	}

	for (int i = 0; i < n; i ++) {
		if (s[i] != t[i]) {
			if (s[i] == '1') {
				if (! mismatch1.empty()) {
					s[i] = '0';
					s[mismatch1.top()] = '1';
					mismatch1.pop();
					res ++;
				}
				else {
					mismatch0.push(i); // mismatched and nothing to swap with so far
				}
			} else if (s[i] == '0' ) {
				if (!mismatch0.empty()) {
					s[i] = '1';
					s[mismatch0.top()] = '0';
					mismatch0.pop();
					res ++;

				} else {
					mismatch1.push(i); // mismatched nd nothing to swap
				}
			}
		}
		if (s[i] == '?' && t[i] == '0') question0.push(i);
		else if (s[i] == '?' && t[i] == '1') question1.push(i);
	
	}
	if (mismatch0.size() > question1.size() ) {
		// we cannot change '1', so we need to check if we can swap it with ? enough times i.e. mismatch0.size() > question1.size(), that way 1 goes to i where s = ? and t = 1
		cout << "Case " << tc << ": " << -1 << '\n';
	} else {
		while (!mismatch0.empty()) {
			mismatch0.pop();
			question1.pop();
			res += 2;// change and set
		}
		// we only have mismatch 1 and ?
		// moves are swap + set or change + set
		// doesnt matter what we do same result
		// result addition is mismatch1.size() + question1.size() + question0.size()
		res += question0.size() + question1.size() + mismatch1.size();
		cout << "Case " << tc << ": " << res << '\n';
	}

	

	
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    cin.ignore();
    //scanf("%d", &tc);
    
    for (int i = 1; i <= tc; i ++ ) {
		dbg("Test Case: ", i);
		solve(i);
	}

	return 0;
}

