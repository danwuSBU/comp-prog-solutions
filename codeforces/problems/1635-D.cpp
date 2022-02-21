#define interactive 1

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = 1e9 + 7; //998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), 0);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

vector<ll> p2;
vector<int> fib;

void solve() {
    int n, p; cin >> n >> p; vector<int> A(n); for EACH(a, A) cin >> a;
    sort(A.begin(), A.end());
    set<int> s;
    ll res = 0;
    for EACH(a, A) {
        int parent = a; bool v = false;
        if (s.count(parent)) v = true;
        while ((parent % 2 == 1 || parent % 4 == 0) && parent > 0) {
            if (parent % 2 == 1) parent /= 2;
            else parent /= 4;
            if (s.count(parent)) v = true;
        }
        if (v) continue;
        s.insert(a);
        int i = bisect_right(p2, (ll) a) - 1;
        if (p - i > 0) res = (res + fib[p - i - 1]) % mod;
    }
    cout << res << '\n';
}

int main() 
{
    p2 = {1};
    REP(33) p2.push_back(p2.back() << 1);
    fib = {1, 1};
    REP(2e5 + 5) fib.push_back((fib.back() + fib.end()[-2]) % mod);
    FOR(i, 1, fib.size()) fib[i] = (fib[i] + fib[i - 1]) % mod;
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}