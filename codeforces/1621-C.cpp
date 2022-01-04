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
    int n; cin >> n;
    vector<int> visited(n, 0);
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        if (visited[i - 1] == 0) {
            vector<int> cycle(2);
            cout << "? " << i << endl;
            cin >> cycle[0];
            cout << "? " << i << endl;
            cin >> cycle[1];
            while (cycle.back() != cycle[0]) {
                cycle.push_back(0);
                cout << "? " << i << endl;
                cin >> cycle.back();
            }
            for (int i = 1; i < cycle.size(); i++) {
                ans[cycle[i - 1] - 1] = cycle[i];
                visited[cycle[i] - 1] = 1;
            }
        }
    }
    cout << "! ";
    output_vector(ans);
}

int main() 
{
    speedup;
    
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}