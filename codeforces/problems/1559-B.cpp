#define interactive 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

void solve() {
    int n; cin >> n;
    vector<char> s(n); for (char &c : s) cin >> c;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == '?') s[i + 1] = 'R';
        if (s[i] == 'R' && s[i + 1] == '?') s[i + 1] = 'B';
    }
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == 'B' && s[i - 1] == '?') s[i - 1] = 'R';
        if (s[i] == 'R' && s[i - 1] == '?') s[i - 1] = 'B';
    }
    if (s[0] == '?') {
        s[0] = 'B';
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == '?') s[i + 1] = 'R';
            if (s[i] == 'R' && s[i + 1] == '?') s[i + 1] = 'B';
        }
    }
    output_vector(s, false);
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}