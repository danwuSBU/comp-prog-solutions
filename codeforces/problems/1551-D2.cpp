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

ll mod = 1e9 + 7; //998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

char nextchar(vector<vector<char>> &g, int x, int y) {
    char ret = 'a';
    while ((x > 0 && ret == g[x - 1][y]) || (x > 0 && y > 0 && ret == g[x - 1][y - 1]) || (y > 0 && ret == g[x][y - 1]) || (x > 0 && y < g[0].size() - 1 && g[x - 1][y + 1] == ret) || (x < g.size() - 1 && y > 0 && g[x + 1][y - 1] == ret)) ret++;
    return ret;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
        if (k % 2 == 0) {
            cout << "YES\n";
            vector<vector<char>> out(n, vector<char>(m, 0));
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    if (k) {
                        k -= 2;
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i][j + 1] = c;
                        c = nextchar(out, i + 1, j);
                        out[i + 1][j] = c; out[i + 1][j + 1] = c;
                    }
                    else {
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i + 1][j] = c;
                        c = nextchar(out, i, j + 1);
                        out[i][j + 1] = c; out[i + 1][j + 1] = c;
                    }
                }
            }
            for EACH(v, out) {
                output_vector(v, false);
            }
        }
        else cout << "NO\n";
    }
    else if (n % 2 == 0) {
        if (k <= n * (m - 1) / 2 && k % 2 == 0) {
            cout << "YES\n";
            vector<vector<char>> out(n, vector<char>(m, 0));
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m - 1; j += 2) {
                    if (k) {
                        k -= 2;
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i][j + 1] = c;
                        c = nextchar(out, i + 1, j);
                        out[i + 1][j] = c; out[i + 1][j + 1] = c;
                    }
                    else {
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i + 1][j] = c;
                        c = nextchar(out, i, j + 1);
                        out[i][j + 1] = c; out[i + 1][j + 1] = c;
                    }
                }
            }
            for (int i = 0; i < n; i += 2) {
                char c = nextchar(out, i, m - 1);
                out[i][m - 1] = c; out[i + 1][m - 1] = c;
            }
            for EACH(v, out) {
                output_vector(v, false);
            }
        }
        else cout << "NO\n";
    }
    else {
        if (k % 2 == (n * m / 2) % 2 && k >= m / 2) {
            cout << "YES\n";
            vector<vector<char>> out(n, vector<char>(m, 0));
            for (int j = 0; j < m; j += 2) {
                k--;
                char c = nextchar(out, 0, j);
                out[0][j] = c; out[0][j + 1] = c;
            }
            for (int i = 1; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    if (k) {
                        k -= 2;
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i][j + 1] = c;
                        c = nextchar(out, i + 1, j);
                        out[i + 1][j] = c; out[i + 1][j + 1] = c;
                    }
                    else {
                        char c = nextchar(out, i, j);
                        out[i][j] = c; out[i + 1][j] = c;
                        c = nextchar(out, i, j + 1);
                        out[i][j + 1] = c; out[i + 1][j + 1] = c;
                    }
                }
            }
            for EACH(v, out) {
                output_vector(v, false);
            }
        }
        else cout << "NO\n";
    }
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}