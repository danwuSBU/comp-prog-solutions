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

string filename = "hps";
ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    int n, k; fin >> n >> k;
    int DP[3][k + 1][n + 1];
    memset( DP, 0, sizeof( DP ) );
    map<char, int> M = {
        {'H', 0},
        {'P', 1},
        {'S', 2}
    };
    vector<int> A(n); for EACH(a, A) {
        char x; fin >> x;
        a = M[x];
    }
    int m = 0;
    FOR(i, 0, 3) {
        FOR(j, 1, n + 1) {
            DP[i][0][j] = DP[i][0][j - 1] + (i == (A[j - 1] + 1) % 3);
            m = max(m, DP[i][0][j]);
        }
    }
    FOR(i, 1, n + 1) {
        FOR(j, 1, k + 1) {
            DP[0][j][i] = max(DP[0][j][i - 1], max(DP[1][j - 1][i - 1], DP[2][j - 1][i - 1])) + (A[i - 1] == 2);
            DP[1][j][i] = max(DP[1][j][i - 1], max(DP[0][j - 1][i - 1], DP[2][j - 1][i - 1])) + (A[i - 1] == 0);
            DP[2][j][i] = max(DP[2][j][i - 1], max(DP[1][j - 1][i - 1], DP[0][j - 1][i - 1])) + (A[i - 1] == 1);
            m = max(m, max({DP[0][j][i], DP[1][j][i], DP[2][j][i]}));
        }
    }
    fout << m;
}

int main()
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    solve();
    return 0;
}