#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
const ll MAX_INT = 2 * 1e5;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll inv(ll a){return powmod(a, mod-2);}
vector<ll> fact(MAX_INT, 1);
ll nCk(ll n, ll k){return ((fact[n] * inv(fact[k]) % mod) * inv(fact[n-k])) % mod;}

void solve() {
}

int main()
{
    // use "\n" instead of cout << endl
    for (int i = 1; i < MAX_INT; i++) fact[i] = (fact[i - 1] * i) % mod;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}
