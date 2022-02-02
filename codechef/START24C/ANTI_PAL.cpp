#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;
vector<ll> bmask;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> cr;
    for EACH(c, s) {
        if (cr.count(c)) cr[c]++;
        else cr[c] = 1;
    }
    vector<pair<char, int>> v;
    for EACH(c, cr) v.push_back(c);
    sort(v.begin(), v.end(), [] (pair<char, int> a, pair<char, int> b) {return a.second < b.second;});
    if (v.back().second * 2 > n || n % 2) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    string res;
    for EACH(pa, v) {
        res += string(pa.second, pa.first);
    }
    string first = res.substr(0, (n + 1) / 2), second = res.substr((n + 1) / 2);
    reverse(second.begin(), second.end());
    cout << first + second << '\n';
}

int main() 
{
    bmask.push_back(1);
    REP(62) bmask.push_back(bmask.back() * 2);
    reverse(bmask.begin(), bmask.end());
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}