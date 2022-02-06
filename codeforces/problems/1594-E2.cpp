#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll inf32 = 1e18;
ll mod = 1e9 + 7; 

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    ll k, n; cin >> k >> n;
    map<ll, ll, greater<ll>> colors;
    map<ll, vector<ll>> marked;
    for (int i = 0; i < n; i++) {
        ll v; string s; cin >> v >> s;
        if (s == "white" || s == "yellow") colors[v] = 0;
        else if (s == "green" || s == "blue") colors[v] = 1;
        else colors[v] = 2;
        while (v >= 1) {
            marked[v] = vector<ll>(6);
            v /= 2;
        }
    }
    for (const auto &[vertex, c] : colors) {
        ll v = vertex;
        while (v >= 1) {
            vector<ll> temp(6, 1);
            if (marked.count(v * 2)) {
                temp[0] *= (marked[v * 2][2] + marked[v * 2][3] + marked[v * 2][4] + marked[v * 2][5]) % mod; temp[0] %= mod;
                temp[1] = temp[0];
                temp[2] *= (marked[v * 2][4] + marked[v * 2][5] + marked[v * 2][0] + marked[v * 2][1]) % mod; temp[2] %= mod;
                temp[3] = temp[2];
                temp[4] *= (marked[v * 2][0] + marked[v * 2][1] + marked[v * 2][2] + marked[v * 2][3]) % mod; temp[4] %= mod;
                temp[5] = temp[4];
            }
            if (marked.count(v * 2 + 1)) {
                temp[0] *= (marked[v * 2 + 1][2] + marked[v * 2 + 1][3] + marked[v * 2 + 1][4] + marked[v * 2 + 1][5]) % mod; temp[0] %= mod;
                temp[1] = temp[0];
                temp[2] *= (marked[v * 2 + 1][4] + marked[v * 2 + 1][5] + marked[v * 2 + 1][0] + marked[v * 2 + 1][1]) % mod; temp[2] %= mod;
                temp[3] = temp[2];
                temp[4] *= (marked[v * 2 + 1][0] + marked[v * 2 + 1][1] + marked[v * 2 + 1][2] + marked[v * 2 + 1][3]) % mod; temp[4] %= mod;
                temp[5] = temp[4];
            }
            if (colors.count(v)) {
                for (int i = 0; i < 6; i++) {
                    if (i != colors[v] * 2) {
                        temp[i] = 0;
                    }
                }
            }
            marked[v] = temp;
            v /= 2;
        }
    }
    ll untotal = powmod(4, (1LL << k) - 1 - marked.size());
    ll total = accumulate(marked[1].begin(), marked[1].end(), 0LL) % mod;
    cout << (untotal * total) % mod;
}

int main() 
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}