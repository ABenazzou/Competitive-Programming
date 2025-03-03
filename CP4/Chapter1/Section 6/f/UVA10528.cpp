
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


vector<string> SCALE = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
vector<int> MAJOR_SCALE = {2, 2, 1, 2, 2, 2, 1}; // t t s t t ts
map<string, set<string>> scales;

void buildMajorScales() {
	for (int i = 0; i < 12; i ++) {
		if (scales.find(SCALE[i]) == scales.end()) {
			set<string> sc;
			sc.insert(SCALE[i]);
			scales[SCALE[i]] = sc; 
		}

		int idxToCheck = i;
		for (int j = 0; j < 7; j ++) {
			idxToCheck += MAJOR_SCALE[j];
			idxToCheck %= 12;
			scales[SCALE[i]].insert(SCALE[idxToCheck]);


		}
	}
	for (pair<string, set<string>> scale: scales) {
		dbg(scale.first, scale.second);
	}

}

void solve() {
	string line;
	buildMajorScales();

	while(getline(cin, line) && line != "END") {
		istringstream iss(line);
		set<string> notes;
		string tmp;
		while (iss >> tmp) {
			notes.insert(tmp);
		}

		string sb = "";
		// gotta check if all the notes are part of a scale 
		for (int i = 0; i < 12; i ++) {
			bool isValid = true;
			for (string note: notes) {
				dbg(SCALE[i], note);
				if (scales[SCALE[i]].find(note) == scales[SCALE[i]].end()) {
					// 1 note not included
					isValid = false;
					break;
				}
			}
			if (isValid) sb += SCALE[i] + " "; 
		}
		
		string res = sb.substr(0, sb.length() - 1);
		cout << res << '\n';


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

