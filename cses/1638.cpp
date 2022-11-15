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
    int n; cin >> n;
    char g[n][n]; FOR(i, 0, n) {
        cin >> g[i];
    }
    int dp[n][n] = {}; dp[0][0] = 1;
    FOR(i, 0, n) {
        FOR (j, 0, n) {
            if (i == 0 && j == 0) {
                if (g[i][j] != '.') {
                    cout << '0';
                    return;
                }
                continue;
            }
            int v = 0;
            if (i - 1 >= 0) v = (v + dp[i - 1][j]) % mod;
            if (j - 1 >= 0) v = (v + dp[i][j - 1]) % mod;
            if (g[i][j] == '.') dp[i][j] = v;
        }
    }
    cout << dp[n - 1][n - 1];
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