#define interactive 1

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = 1e9 + 7; //998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), 0);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

void solve() {
    int n, m; cin >> n >> m;
    int dp[n][m + 1]; memset(dp, 0, sizeof(dp));
    vector<int> A(n); for EACH(a, A) cin >> a;
    if (A[0]) dp[0][A[0]] = 1;
    else FOR(i, 1, m + 1) dp[0][i] = 1;
    FOR(i, 1, n) {
        if (A[i]) {
            dp[i][A[i]] = dp[i - 1][A[i]];
            dp[i][A[i]] = (dp[i][A[i]] + dp[i - 1][A[i] - 1]) % mod;
            if (A[i] < m) dp[i][A[i]] = (dp[i][A[i]] + dp[i - 1][A[i] + 1]) % mod;
        }
        else {
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
            dp[i][m] = (dp[i][m] + dp[i - 1][m]) % mod;
            if (m - 1 > 0) dp[i][m - 1] = (dp[i][m - 1] + dp[i - 1][m]) % mod;
            FOR(j, 1, m) {
                if (j - 1 > 0) dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }
    if (A.back()) cout << dp[n - 1][A.back()];
    else {
        int ret = 0;
        FOR(i, 0, m + 1) ret = (ret + dp[n - 1][i]) % mod;
        cout << ret;
    }
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; FOR(i, 1, t + 1) {
            cout << t << ' ';
            solve();
        }
    }
    return 0;
}