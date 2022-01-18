#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive false

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
    int n, m, r, c; cin >> n >> m >> r >> c;
    vector<vector<char>> G(n, vector<char>(m));
    bool has = false;
    for (vector<char> &v : G) {
        for (char &c : v) {
            cin >> c;
            if (c == 'B') has = true;
        }
    }
    if (!has) {
        cout << "-1\n";
        return;
    }
    if (G[r - 1][c - 1] == 'B') {
        cout << "0\n";
        return;
    }
    has = false;
    for (int i = 0; i < n; i++) {
        if (G[i][c - 1] == 'B') has = true;
    }
    for (int i = 0; i < m; i++) {
        if (G[r - 1][i] == 'B') has = true;
    }
    if (has) cout << "1\n";
    else cout << "2\n";
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