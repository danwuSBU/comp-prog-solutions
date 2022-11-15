#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = /*1e9 + 7;*/ 998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

string filename = "feast";
string file_in = filename + ".in", file_out = filename + ".out";

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int t, a, b; cin >> t >> a >> b;
    bool dp[t + 1] = {false}; dp[0] = true;
    FOR(i, 1, t + 1) {
        if (i - a >= 0 && dp[i - a]) dp[i] = true;
        if (i - b >= 0 && dp[i - b]) dp[i] = true; 
    }
    vector<int> f; FOR(i, 1, t + 1) if (dp[i]) f.push_back(i);
    int best = f.back();
    for EACH(x, f) {
        best = max(best, (x / 2) + *--upper_bound(f.begin(), f.end(), (t - (x / 2))));
    }
    cout << best;
}

int main()
{
    freopen(&file_in[0], "r", stdin);
    freopen(&file_out[0], "w", stdout);
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    solve();
    return 0;
}
