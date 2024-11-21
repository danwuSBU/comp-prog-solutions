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
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    FOR(i, 0, n) FOR(j, 0, m) {
        int x; cin >> x;
        A[i][j] = x;
    }
    set<p> V; vector<p> S;
    int c = 0, ma = 0;
    FOR(i, 0, n) FOR(j, 0, m) {
        if (V.count(p(i, j))) continue;
        c = 0;
        S.push_back(p(i, j));
        while (S.size()) {
            p x = S.back();
            S.pop_back();
            if (V.count(x) || x.first < 0 || x.second < 0 || x.first >= n || x.second >= m || !A[x.first][x.second]) continue;
            V.insert(x);
            c += A[x.first][x.second];
            S.push_back(p(x.first + 1, x.second));
            S.push_back(p(x.first - 1, x.second));
            S.push_back(p(x.first, x.second + 1));
            S.push_back(p(x.first, x.second - 1));
        }
        ma = max(ma, c);
    }
    cout << ma << '\n';
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