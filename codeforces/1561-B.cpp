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

template <typename T> void output_set(set<T> S) {
    for (auto s : S) cout << s << ' ';
    cout << endl;
}

void solve() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    set<int> ret;
    for (int i = (a + b) / 2 - a; i <= (a + b) / 2 + a; i += 2) ret.insert(i);
    if ((a + b) % 2) for (int i = (a + b) / 2 + 1 - a; i <= (a + b) / 2 + 1 + a; i += 2) ret.insert(i);
    cout << ret.size() << '\n';
    output_set(ret);
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}