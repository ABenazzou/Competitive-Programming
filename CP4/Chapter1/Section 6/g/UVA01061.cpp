
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

void _out(set<string> _in) {
	if (_in.size() == 1) cout << *_in.begin();
	else cout << _in;
}

map<string, vector<char>> possibleAlleles = {{"A", {'A', 'O'}}, {"B", {'B', 'O'}}, {"AB", {'A', 'B'}}, {"O", {'O'}}};
map<string, string> result = {{"AB", "AB"}, {"AA", "A"}, {"BB", "B"}, {"OO", "O"}, {"BO", "B"}, {"AO", "A"}};
void solve() {
	string p1, p2, c;
	int tc = 1;
	while (cin >> p1 >> p2 >> c && (p1 != "E")) {
		bool isParent = (p2 == "?" || p1 == "?");
		if (isParent) {
			// solve for parent
			// given parent and children, possible for p2?
			// if its negative, parents can be anything 
			// if its positive, parents can be anything except double negative
			string _parent = (p1 == "?") ? p2 : p1;
			bool isNotNegative = _parent[_parent.length() - 1] == '-' && c[c.length() - 1] == '+';

			// now blood
			// if child is O, -> OO -> parents either A, B or O, never AB for anyone
			// if child is AB -> one parent should have A and ther other B [A B, AB B, AB A] 
			// if child is A -> parents: AB + whatever, A + whatever, B + A or AB, O + A or AB --> one has A
			// if child is B -> one has B
			bool impossible = false;
			set<string> results;
			string parent = _parent.substr(0, _parent.length() - 1);
			string _c = c.substr(0, c.length() - 1);
			vector<string> bloods;
			if (_c == "O") {
				if (parent == "AB") impossible = true;
				else {
					// anything except AB
					bloods = {"A", "B", "O"};
				}
			} else if (_c == "A" || _c == "B") {
				// one has A and the other could be everything [B -> BO -> AO -> A]
				bloods = {"A", "B", "O", "AB"};
				if (parent.find(_c) == string::npos) {
					// the first parent doesnt have A or B - > the other parent should have it in their blood
					bloods.erase(bloods.begin() + 2);
					string toRemove = (_c == "A") ? "B" : "A";
					bloods.erase(find(bloods.begin(), bloods.end(), toRemove));
				}
			} else {
				// AB -> one parent provides A and the other B e.g. if one parent is O -> IMPOSSIBLE
				// if one parent is A the other parent should have B
				// if one parent is B the other parent should have A
				// if one parent is AB the other parent can have either A or B
				if (parent == "O") impossible = true;
				else {
					bloods = {"A", "B", "AB"};
					if (parent == "A") {
						bloods.erase(bloods.begin());
					} else if (parent == "B") {
						bloods.erase(bloods.begin() + 1);
					}
					

				}

			}
			cout << "Case " << tc ++ << ": ";
			if (! impossible) {
				string tmp;
				for (string blood: bloods) {
					tmp = blood;
					results.insert(tmp + "+");
					if (! isNotNegative) {
						results.insert(tmp + "-");
					}
				}
				if (p1 == "?") { _out(results); cout << " " << p2 << " ";}
				else { cout << p1 << " "; _out(results); cout << " ";}


			} else {
				if (p1 == "?") cout << "IMPOSSIBLE " << p2 << " ";
				else cout << p1 << " IMPOSSIBLE ";
			}
			cout << c << '\n';
		} else {
			// solve for children
			bool isNegative = p1[p1.length() - 1] == '-' && p2[p2.length() - 1] == '-';
			vector<char> possibleP1 = possibleAlleles[p1.substr(0, p1.length() - 1)];
			vector<char> possibleP2 = possibleAlleles[p2.substr(0, p2.length() - 1)];
			set<string> results;

			// o(n2) bcz very small sample
			for (char x: possibleP1) {
				string possibility;
				possibility.push_back(x);
				for(char y: possibleP2){
					string tmp = possibility;
					tmp.push_back(y);
					sort(tmp.begin(), tmp.end());
					tmp = result[tmp];
					results.insert(tmp + "-");
					if (! isNegative) results.insert(tmp + "+");
				}
			}
			cout << "Case " << tc ++ << ": " << p1 << " " << p2 << " ";
			_out(results);
			cout << '\n';

		}
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

