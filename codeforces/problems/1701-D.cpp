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
    struct seg {
        int i, x, y;
        bool operator<(const seg &a) const {
            return y < a.y;
        }
    };
    int n; cin >> n;
    vector<int> B(n); for EACH(b, B) cin >> b;
    vector<seg> S(n);
    FOR(j, 0, n) {
        S[j].i = j;
        S[j].x = floor(1.0 * (j + 1) / (B[j] + 1) + 1);
        S[j].y = (B[j]) ? (j + 1) / B[j] : BIG32;
    }
    sort(S.begin(), S.end(), [] (seg a, seg b) {return tie(a.x, a.y) < tie(b.x, b.y);});
    vector<int> O(n); multiset<seg> T;
    int k = 0;
    FOR(j, 0, n) {
        while (k < S.size() && S[k].x <= j + 1) {
            int x = T.size();
            T.insert(S[k]);
            int y = T.size();
            k++;
        }
        O[(*T.begin()).i] = j + 1;
        T.erase(T.begin());
    }
    output_vector(O);
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