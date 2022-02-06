#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive true

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    if (interactive) cout << endl;
    else cout << '\n';
}
template <typename T> T max(vector<T> V) {
    return *max_element(V.begin(), V.end());
}
template <typename T> T min(vector<T> V) {
    return *min_element(V.begin(), V.end());
}

void solve() {
    ll n, l, k; cin >> n >> l >> k;
    vector<int> D(n); for (int &d : D) cin >> d; D.push_back(l);
    vector<int> A(n); for (int &a : A) cin >> a;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, BIG32));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int put = i + 1; put <= n; put++) {
                int skipped = put - i - 1;
                if (j + skipped <= k) {
                    dp[put][j + skipped] = min(dp[put][j + skipped], dp[i][j] + (D[put] - D[i]) * A[i]);
                }
            }
        }
    }
    cout << min(dp.back()) << '\n';
}

int main() 
{
    speedup;
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}