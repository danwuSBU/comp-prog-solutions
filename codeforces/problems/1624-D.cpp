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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> counter(26, 0);
    for (char x : s) counter[x - 'a']++;
    int pairs = 0, leftover = 0;
    for (int c : counter) {
        pairs += c / 2;
        leftover += c % 2;
    }
    int longest = (pairs / k) * 2;
    leftover += (pairs * 2) - (longest * k);
    if (leftover >= k) longest++;
    cout << longest << '\n';
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}