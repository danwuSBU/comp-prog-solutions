#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = /*1e9 + 7;*/ 998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> int bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> int bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int n, m; cin >> n >> m;
    string G[n]; p a(0, BIG32), b(BIG32, 0), c(-BIG32, 0), d(BIG32, 0);
    FOR(i, 0, n) {
        cin >> G[i];
        FOR(j, 0, m) {
            if (G[i][j] == 'B') {
                if (a.first - a.second < i - j) a.first = i, a.second = j;
                if (b.first - b.second > i - j) b.first = i, b.second = j;
                if (c.first + c.second < i + j) c.first = i, c.second = j;
                if (d.first + d.second > i + j) d.first = i, d.second = j;
            }
        }
    }
    auto md = [] (p a, p b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    int bd = BIG32;
    p be;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int di = 0;
            di = max(di, md(p(i, j), a));
            di = max(di, md(p(i, j), b));
            di = max(di, md(p(i, j), c));
            di = max(di, md(p(i, j), d));
            if (di < bd) {
                bd = di;
                be = p(i, j);
            }
        }
    }
    cout << be.first + 1 << ' ' << be.second + 1 << '\n';
}

int main()
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}