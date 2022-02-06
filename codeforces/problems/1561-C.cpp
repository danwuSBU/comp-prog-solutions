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

void solve() {
    int n; cin >> n;
    vector<vector<int>> C(n);
    for (vector<int> &c : C) {
        int k; cin >> k;
        c = vector<int>(k);
        for (int &m : c) cin >> m;
    }
    auto cavelvl = [] (vector<int> c) {
        int m = 0;
        for (int i = 0; i < c.size(); i++) {
            m = max(m, c[i] - i);
        }
        return m;
    };
    sort(C.begin(), C.end(), [&](vector<int> a, vector<int> b) {return cavelvl(a) < cavelvl(b);});
    int current = 0, diff = 0;
    for (vector<int> &c : C) {
        for (int k : c) {
            diff = max(diff, k - current);
            current++;
        }
    }
    cout << diff + 1 << '\n';
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}