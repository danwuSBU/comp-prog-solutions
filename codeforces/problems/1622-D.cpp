#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, double> pd;
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll inv(ll a){return powmod(a, mod-2);}
int MAX_INT = 5001;
vector<ll> fact(MAX_INT, 1);
ll nCk(ll n, ll k){return ((fact[n] * inv(fact[k]) % mod) * inv(fact[n-k])) % mod;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}
 
unordered_map<string, int> memo;
 
int combinations(string s) {
    if (memo.count(s)) return memo[s] - 1;
    int ones = count(s.begin(), s.end(), '1');
    memo[s] = nCk(s.length(), ones);
    return memo[s] - 1;
}
 
void solve() {
    int n, k; cin >> n >> k; string s; cin >> s;
    if (k == 0 || count(s.begin(), s.end(), '1') < k) {
        cout << "1\n"; return;
    }
    int l = 0, r = -1, ones = 0;
    while (r < n - 1 && (ones < k || s[r + 1] == '0')) {
        r++;
        if (s[r] == '1') ones++;
    }
    int prevl = l, prevr = r; ll total = combinations(s.substr(l, r - l + 1)) + 1;
    while (r < n - 1) {
        r++;
        if (s[r] == '1') {
            while (r < n - 1 && s[r + 1] == '0') r++;
            while (l <= r && s[l] == '0') l++;
            l++; if (l > r) break;
            if (l != r) total = (total + combinations(s.substr(l, r - l + 1))) % mod;
            if (l <= prevr) total = (total + mod - combinations(s.substr(l, prevr - l + 1))) % mod;
            prevl = l, prevr = r;
        }
    }
    cout << total << '\n';
}
 
int main() 
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    for (int i = 1; i < MAX_INT; i++) fact[i] = (fact[i - 1] * i) % mod;
    cin.tie(NULL);
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}
