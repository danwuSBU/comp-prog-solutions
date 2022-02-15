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
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), 0);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for EACH(a, A) cin >> a;
    for EACH(b, B) cin >> b;
    FOR(i, 0, n) {
        if (A[i] > B[i]) swap(A[i], B[i]);
    }
    int mx = sum(B);
    map<int, vector<int>> s;
    s[0] = vector<int>(n, 0);
    FOR(i, 0, n) {
        vector<pair<int, vector<int>>> to_add;
        for EACH(x, s) {
            vector<int> y(x.second);
            y[i] = 1;
            to_add.emplace_back(x.first + B[i] - A[i], y);
        }
        for EACH(x, to_add) s.insert(x);
    }
    double goal = (sum(A) + sum(B)) / 2.0 - sum(A);
    pair<int, vector<int>> best;
    double bdiff = BIG32;
    for EACH(x, s) {
        if (abs(x.first - goal) < bdiff) {
            best = x;
            bdiff = abs(x.first - goal);
        }
    }
    FOR(i, 0, n) {
        if (best.second[i]) swap(A[i], B[i]);
    }
    int out = 0;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            out += (A[i] + A[j]) * (A[i] + A[j]) + (B[i] + B[j]) * (B[i] + B[j]);
        }
    }
    cout << out << '\n';
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