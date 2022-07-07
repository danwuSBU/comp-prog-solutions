#define interactive 0

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_, 0, a)
#define EACH(a, x) (auto &a: x)

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
    int g[405][405] = {0};
    FOR(i, 1, n + 1) {
        string s; cin >> s;
        FOR(j, 1, m + 1) {
            g[i][j] = s[j - 1] - '0';
        }
    }
    FOR(i, 1, n + 1) FOR(j, 1, m + 1) g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    auto ps = [g] (int a, int b, int c, int d) {
        return g[a][b] - g[c - 1][b] - g[a][d - 1] + g[c - 1][d - 1];
    };
    int b = BIG32;
    FOR(i, 1, n - 3) {
        FOR(j, i + 4, n + 1) {
            vector<int> P(m + 1); int best = BIG32; P[0] = BIG32;
            FOR(k, 1, m - 2) {
                int curr = ps(j - 1, m, i + 1, k + 1) + 
                           2 * (m - k) - 
                           ps(i, m, i, k + 1) - 
                           ps(j, m, j, k + 1) - 
                           ps(j - 1, k, i + 1, k);
                if (curr < best) {
                    P[k] = k;
                    best = curr;
                }
                else P[k] = P[k - 1];
            }
            FOR(r, 4, m + 1) {
                int l = P[r - 3];
                int sub = ps(j - 1, r - 1, i + 1, l + 1),
                cols = (j - i - 1) * 2 - ps(j - 1, l, i + 1, l) - ps(j - 1, r, i + 1, r),
                rows = (r - l - 1) * 2 - ps(i, r - 1, i, l + 1) - ps(j, r - 1, j, l + 1);
                b = min(b, sub + cols + rows);
            }
        }
    }
    cout << b << '\n';
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