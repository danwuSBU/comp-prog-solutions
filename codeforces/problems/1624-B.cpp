#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7; 

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << endl;
}
template <typename T> T max(vector<T> V) {
    return *max_element(V.begin(), V.end());
}
template <typename T> T min(vector<T> V) {
    return *min_element(V.begin(), V.end());
}

void solve() {
    int a, b, c; cin >> a >> b >> c; bool ok = false;
    if ((b - a + b) > 0 && (b - a + b) % c == 0) ok = true;
    if ((c - a) % 2 == 0 && (a + (c - a) / 2) % b == 0) ok = true;
    if (b - (c - b) > 0 && (b - (c - b)) % a == 0) ok = true;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}