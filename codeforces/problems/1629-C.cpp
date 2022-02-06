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
    int n, m = 0; cin >> n;
    vector<int> A(n), out; for EACH(a, A) cin >> a;
    vector<int> MEXT(n); set<int> t;
    ROF(i, 0, n) {
        t.insert(A[i]);
        while (t.count(m)) m++;
        MEXT[i] = m;
    }
    int index = 0;
    while (index < n) {
        set<int> s;
        int MEX = 0, best = 0;
        FOR(i, index, n) {
            s.insert(A[i]);
            while (s.count(MEX)) MEX++;
            if (MEX == MEXT[index]) {
                index = i + 1;
                break;
            }
        }
        out.push_back(MEX);
    }
    cout << out.size() << '\n';
    output_vector(out);
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