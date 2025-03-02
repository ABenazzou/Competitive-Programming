
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

int getSimultaneousTime(vi &cycles) {
	dbg(cycles);
	int n = cycles.size();
	int minChange = *min_element(cycles.begin(), cycles.end());
	for (int i = minChange + 1; i <= 18000; i ++) {
		// skip first greeen lights to
		// 5 hours
		bool allOn = true;
		for (int j = 0; j < n; j ++) {
			int currTime = i % (2 * cycles[j]);
			// get current time within the cycle e.g. 2*k <= x < 4*k
			if (currTime >= cycles[j] - 5) {
				// red phase? 0 -> cycle - 5
				// orange + red phase - > cycle -5 -> cycle, cycle -> 2 * cycle - 1
				allOn = false;
				break;

			}
		}
		if (allOn) {
			cycles.clear();
			return i;
		}
	}
	cycles.clear();
	return -1;
}

void printTime(int time) {
	int hours = time / 3600;
	time -= hours * 3600;
	int minutes = time / 60;
	time -= minutes * 60;
	cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << time << '\n';
}

void solve() {
	vi cycles;
	int a, b, c;
	while (cin >> a >> b >> c && (a || b || c)) {
		// min scenario = 2 -> c could be a 0
		cycles.push_back(a);
		cycles.push_back(b);
		if (c) {
			cycles.push_back(c);
			while (cin >> c && c) {
				cycles.push_back(c);
			}
		}
		
		int res = getSimultaneousTime(cycles);
		if (res != -1) printTime(res);
		else cout << "Signals fail to synchronise in 5 hours\n";
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

