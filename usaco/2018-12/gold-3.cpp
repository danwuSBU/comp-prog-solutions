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

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

string filename = "teamwork";
ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int n, k; fin >> n >> k;
    vector<int> A(n); for EACH(a, A) fin >> a;
    vector<int> DP(A); FOR(i, 1, n) DP[i] += DP[i - 1];
    FOR(i, 0, n) {
        int curr = A[i];
        FOR(j, 0, k) {
            if (i - j >= 0) {
                curr = max(curr, A[i - j]);
                DP[i] = max(DP[i], curr * (j + 1) + (i - j - 1 >= 0 ? DP[i - j - 1] : 0));
            }
        }
    }
    fout << DP.back();
}

int main()
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    solve();
    return 0;
}