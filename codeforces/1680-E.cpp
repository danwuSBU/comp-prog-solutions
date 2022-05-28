#define interactive 0

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

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int n; cin >> n;
    string s[2]; cin >> s[0] >> s[1];
    int i = 0; for (i; i < n; i++) {
        if (s[0][i] != '.' || s[1][i] != '.') break;
    }
    s[0] = s[0].substr(i), s[1] = s[1].substr(i);
    while (s[0].back() == '.' && s[1].back() == '.') s[0].pop_back(), s[1].pop_back();
    vector<vector<int>> dp(2, vector<int>(s[0].size()));
    dp[0][0] = (s[1][0] == '*') ? 1 : 0;
    dp[1][0] = (s[0][0] == '*') ? 1 : 0;
    FOR(i, 1, s[0].size()) {
        dp[0][i] = min(1 + dp[0][i - 1] + (s[1][i] == '*'), 2 + dp[1][i - 1]);
        dp[1][i] = min(1 + dp[1][i - 1] + (s[0][i] == '*'), 2 + dp[0][i - 1]);
    }
    cout << min(dp[0].back(), dp[1].back()) << '\n';
}

int main()
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}