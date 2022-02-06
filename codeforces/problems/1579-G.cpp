#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive false

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

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
    int n, a, mx = 0; cin >> n;
    vector<int> A(n); for (int &a : A) {
        cin >> a;
        mx = max(a, mx);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * mx + 1, BIG32));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * mx + 1; j++) {
            if (dp[i][j] == BIG32) continue;
            dp[i + 1][max(0, j - A[i])] = min(dp[i + 1][max(0, j - A[i])], dp[i][j] + A[i]);
            if (j + A[i] < 2 * mx + 1) dp[i + 1][j + A[i]] = min(dp[i + 1][j + A[i]], max(0, dp[i][j] - A[i]));
        }
    }
    int m = BIG32;
    for (int j = 0; j < 2 * mx + 1; j++) {
        m = min(m, j + dp.back()[j]);
    }
    cout << m << '\n';
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