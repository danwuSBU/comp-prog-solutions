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
    int n; cin >> n;
    vector<int> K(n); for (int &k : K) cin >> k;
    vector<int> H(n); for (int &h : H) cin >> h;
    ll mana = 0;
    int index = n - 1;
    while (index >= 0) {
        int b = index;
        int hp = H[index];
        while (index > 0 && K[b] - K[index - 1] < hp) {
            if (H[index - 1] > hp - (K[b] - K[index - 1])) {
                hp = H[index - 1] + (K[b] - K[index - 1]);
            }
            index--;
        }
        mana += 1LL * hp * (hp + 1) / 2;
        index--;
    }
    cout << mana << '\n';
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