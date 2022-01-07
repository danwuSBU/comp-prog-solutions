#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7; 

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >=0 ); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << endl;
}

void solve() {
    int n, k = 0, response; cin >> n;
    vector<int> q(n, 1);
    vector<int> result(n, -1);
    for (int i = n; i > 1; i--) {
        q.back() = i;
        cout << "? "; output_vector(q);
        cin >> k;
        if (k) {
            k = n + 1 - i; break;
        }
    }
    if (!k) k = n;
    result.back() = k;
    for (int i = 1; i <= n; i++) {
        if (i < k) {
            cout << "? "; for (int j = 0; j < n - 1; j++) cout << k + 1 - i << " "; cout << "1" << endl;
            cin >> response; result[response - 1] = i;
        }
        if (i > k) {
            cout << "? "; for (int j = 0; j < n - 1; j++) cout << "1 "; cout << i + 1 - k << endl;
            cin >> response; result[response - 1] = i;
        }
    }
    cout << "! "; output_vector(result);
}

int main() 
{
    speedup;
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}