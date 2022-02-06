#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

void solve() {
    int n, m, l, r, x; cin >> n >> m;
    int o = 0;
    while (m--) {
        cin >> l >> r >> x;
        o |= x;
    }
    cout << (o * powmod(2, n - 1)) % mod << '\n';
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}