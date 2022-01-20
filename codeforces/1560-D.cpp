#define interactive 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V) {for (auto v : V) cout << v << ' '; if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

void solve() {
    string n; cin >> n;
    vector<ll> powers{1};
    for (int i = 0; i < 60; i++) {
        powers.push_back(powers.back() << 1);
    }
    int minops = BIG32;
    for (ll &p : powers) {
        string s = to_string(p);
        int ops = 0, j = 0;
        for (int i = 0; i < n.length(); i++) {
            if (j < s.length() && s[j] == n[i]) j++;
            else ops++;
        }
        ops += s.length() - j;
        minops = min(minops, ops);
    }
    cout << minops << '\n';
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