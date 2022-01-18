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
    string xs; cin >> xs;
    for (int i = xs.length() - 1; i > 0; i--) {
        if (xs[i] + xs[i - 1] - 96 > 9) {
            cout << xs.substr(0, i - 1) + to_string(xs[i] + xs[i - 1] - 96);
            for (int j = i + 1; j < xs.length(); j++) cout << xs[j];
            cout << '\n';
            return;
        }
    }
    cout << to_string(xs[0] + xs[1] - 96);
    for (int i = 2; i < xs.length(); i++) cout << xs[i];
    cout << '\n';
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