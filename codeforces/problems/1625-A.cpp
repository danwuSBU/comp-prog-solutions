#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive false

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

vector<int> bitmask(1);
 
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

struct edge {
    int u, v, w;
};

void solve() {
    int n, l; cin >> n >> l;
    vector<int> words(n);
    for (int &w : words) cin >> w;
    int out = 0;
    for (int &b : bitmask) {
        int ones = 0;
        for (int &w : words) {
            if (b & w) ones++;
        }
        out <<= 1;
        if (ones > n / 2) out++;
    }
    cout << out << '\n';
}

int main() 
{
    bitmask[0] = 1;
    for (int i = 0; i < 30; i++) {
        bitmask.push_back(bitmask.back() << 1);
    }
    reverse(bitmask.begin(), bitmask.end());
    speedup;
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}