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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    auto trim = [] (string &x) {
        string y;
        for EACH(a, x) {
            if (a != 'b') y.push_back(a);
        }
        return y;
    };
    if (trim(s) != trim(t)) {
        cout << "NO\n"; return;
    }
    int i = 0, j = 0, ib = 0, jb = 0;
    while (i < n && j < n) {
        while (s[i] == 'b' && i < n) {
            ib++;
            i++;
        }
        while (t[j] == 'b' && j < n) {
            j++;
            jb++;
        }
        if (i < n && s[i] == 'a') {
            if (ib > jb) {
                cout << "NO\n";
                return;
            }
        }
        i++, j++;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    i = 0, j = 0, ib = 0, jb = 0;
    while (i < n && j < n) {
        while (s[i] == 'b' && i < n) {
            ib++;
            i++;
        }
        while (t[j] == 'b' && j < n) {
            j++;
            jb++;
        }
        if (i < n && s[i] == 'c') {
            if (ib > jb) {
                cout << "NO\n";
                return;
            }
        }
        i++, j++;
    }
    cout << "YES\n";
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