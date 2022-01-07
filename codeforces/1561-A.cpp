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
    vector<int> A(n); for (int &a : A) cin >> a;
    bool parity = true;
    auto sorted = [](vector<int> X) {
        for (int i = 1; i < X.size(); i++) {
            if (X[i] < X[i - 1]) return false;
        }
        return true;
    };
    int iterations = 0;
    while (!sorted(A)) {
        if (parity) {
            for (int i = 0; i <= n - 3; i += 2) {
                if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
            }
        }
        else {
            for (int i = 1; i <= n - 2; i += 2) {
                if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
            }
        }
        parity = !parity;
        iterations++;
    }
    cout << iterations << '\n';
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}