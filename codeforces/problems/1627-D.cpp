#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive true

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
    int n, c; cin >> n;
    int MAX = 1000005;
    bool ok[MAX] = {false};
    for (int i = 0; i < n; i++) {
        cin >> c;
        ok[c] = true;
    }
    for (int i = 1; i < MAX; i++) {
        if (!ok[i]) {
            int curr = 0;
            for (int j = i; j < MAX; j += i) {
                if (ok[j]) curr = __gcd(curr, j);
            }
            if (curr == i) ok[i] = true;
        }
    }
    cout << count(ok, ok + MAX, true) - n;
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