
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
 

map<string, int> STR_ROW = {
    {"qwertyuiop", 0},
    {"asdfghjkl", 1},
    {"zxcvbnm", 2}
};
map<string, int> STR_COL = {
    {"qaz", 0},
    {"wsx", 1},
    {"edc", 2},
    {"rfv", 3},
    {"tgb", 4},
    {"yhn", 5},
    {"ujm", 6},
    {"ik", 7},
    {"ol", 8},
    {"p", 9}
};

struct Comparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first > b.first; // smaller int
        }
        // otherwise alphab
        return a.second > b.second;
    }
};

void setup_mapping(map<char, int> &row, map<char, int> &col) {
    for (pair<string, int> p : STR_ROW) {
        for (char c : p.first) {
            row[c] = p.second;
        }
    }

    for (pair<string, int> p : STR_COL) {
        for (char c : p.first) {
            col[c] = p.second;
        }
    }

}

int get_distance(string spell, string typed, map<char, int> &ROW, map<char, int> &COL) {
    int dist = 0;
    for (int i = 0; i < spell.size(); i++) {
        dist += abs(ROW[spell[i]] - ROW[typed[i]]) + abs(COL[spell[i]] - COL[typed[i]]);
    }
    return dist;
 
}

 void solve() {
    map<char, int> mapping_row, mapping_col;
    setup_mapping(mapping_row, mapping_col);
    string w;
    int l;
    cin >> w >> l;
    string tmp;
    priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> res;
    for (int i = 0; i < l; i ++) {
        cin >> tmp;
        // compute distance to w and store in a pq
        int distance = get_distance(tmp, w, mapping_row, mapping_col);
        res.push(make_pair(distance, tmp));
    }     
    while(!res.empty()) {
        cout << res.top().second << " " << res.top().first << '\n';
        res.pop();
    }

 }
 
 
 int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     
     int tc = 1;
     cin >> tc;
     //scanf("%d", &tc);
     
     for (int i = 1; i <= tc; i ++ ) {
         dbg("Test Case: ", i);
         solve();
     }
 
     return 0;
 }
 
 