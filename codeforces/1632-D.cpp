#define interactive 1

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

struct node {
    node *l, *r;
    int v;
    node(node *tl, node *tr) {
        l = tl;
        r = tr;
        v = __gcd(tl->v, tr->v); // change to operation
    }
    node(int x) {
        l = r = nullptr;
        v = x;
    }
};
int a[200000]; // max size
node* build(int tl, int tr) { // build in range 0 to n
    if (tl == tr - 1) {
        return new node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm, tr));
    }
}
int query(node *t, int tl, int tr, int l, int r) { // not r-inclusive
    if(l >= r) return 0;
    if(tl == l && tr == r) return t->v;
    int tm = (tl + tr) / 2;
    int r1 = query(t->l, tl, tm, l, min(r, tm));
    int r2 = query(t->r, tm, tr, max(l, tm), r);
    return __gcd(r1, r2); // change to operation
}

void solve() {
    int n; cin >> n;
    FOR(i, 0, n) cin >> a[i];
    vector<int> C(n, -1);
    node *t = build(0, n);
    FOR(i, 0, n) {
        int low = i, mid, high = n, ans;
        while (low <= high) {
            mid = (high - low) / 2 + low;
            if (query(t, 0, n, i, mid) >= mid - i) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (query(t, 0, n, i, ans) == ans - i) {
            C[i] = ans - 1;
        }
    }
    vector<int> D(n, 0);
    int i = 0;
    while (i < n) {
        if (C[i] >= 0) {
            D[C[i]] = 1;
            i = C[i];
        }
        i++;
    }
    FOR(i, 1, n) D[i] += D[i - 1];
    output_vector(D);
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