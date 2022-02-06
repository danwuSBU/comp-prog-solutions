#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}

void solve() {
    int n, k; cin >> n >> k;
    int mask = n - 1;
    if (k == n - 1) {
        if (n == 4) cout << "-1\n";
        else {
            cout << n - 1 << ' ' << n - 2 << '\n';
            cout << 1 << ' ' << n - 3 << '\n';
            cout << "0 2\n";
            FOR(i, 3, n - 3) {
                if (i < n - 1 - i) cout << i << ' ' << ((~i) & mask) << '\n';
            }
        }
    }
    else {
        int skip = (~k) & mask;
        cout << k << ' ' << n - 1 << '\n';
        if (k != 0) cout << skip << ' ' << "0\n";
        FOR(i, 1, n / 2) {
            if (i == skip || i == k) continue;
            cout << i << ' ' << ((~i) & mask) << '\n';
        }
    }
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