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

struct segment {
    int l, r, c;
};

void solve() {
    int n; cin >> n;
    map<p, int> smap;
    vector<segment> A(n); for (auto &a : A) {
        cin >> a.l >> a.r >> a.c;
    }
    cout << A[0].c << '\n';
    segment ls = A[0], rs = A[0]; smap[p(A[0].l, A[0].r)] = A[0].c;
    for (int i = 1; i < n; i++) {
        if (smap.count(p(A[i].l, A[i].r))) smap[p(A[i].l, A[i].r)] = min(A[i].c, smap[p(A[i].l, A[i].r)]);
        else smap[p(A[i].l, A[i].r)] = A[i].c;
        if (A[i].l < ls.l || (A[i].l == ls.l && ls.c > A[i].c)) ls = A[i];
        if (A[i].r > rs.r || (A[i].r == rs.r && rs.c > A[i].c)) rs = A[i];
        if (smap.count(p(ls.l, rs.r))) cout << min(ls.c + rs.c, smap[p(ls.l, rs.r)]) << '\n';
        else cout << ls.c + rs.c << '\n';
    }
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