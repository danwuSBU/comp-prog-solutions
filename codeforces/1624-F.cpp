#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive true

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;

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
    int added = 0, low = 1, high = n, curr = 0, next;
    auto query = [&] (int c) {
        added = (added + c) % n;
        cout << "+ " << c << endl;
        int xn; cin >> xn;
        return xn;
    };
    while (low + 1 < high) {
        int mid = (high - low) / 2 + low;
        int add = n - mid % n;
        int next = query(add);
        if (next != curr) low = mid;
        else high = mid;
        low += add; high += add;
        curr = next;
    }
    cout << "! " << low << '\n';
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