#define interactive 0

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

vector<int> minops(1001, BIG32); int maxminops;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> B(n), C(n);
    for EACH(b, B) cin >> b;
    for EACH(c, C) cin >> c;
    vector<int> prev(k + 1, 0);
    int current = 0;
    FOR(i, 1, n + 1) {
        int cost = minops[B[i - 1]], value = C[i - 1];
        ROF(j, max(cost, k - maxminops), k + 1) {
            prev[j] = max(prev[j], prev[j - cost] + value);
        }
    }
    cout << max(prev) << '\n';
}

int main() 
{
    minops[1] = 0;
    FOR(i, 1, 1001) {
        FOR(j, 1, i + 1) {
            if (i + (int) ((double) i / j) < 1001) {
                minops[i + (int) ((double) i / j)] = min(minops[i + (int) ((double) i / j)], minops[i] + 1);
            }
        }
    }
    maxminops = max(minops);
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}