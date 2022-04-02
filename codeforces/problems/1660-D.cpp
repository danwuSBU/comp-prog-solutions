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
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {
    
}
// preprocess //

void solve() {
    int n; cin >> n;
    vector<vector<int>> A;
    FOR(i, 0, n) {
        int x; cin >> x;
        if (!i) A.push_back(vector<int>{x});
        else {
            if (!x || !A.back().back()) {
                A.push_back(vector<int>{x});
            }
            else A.back().push_back(x);
        }
    }
    int mp = 0, l = n, r = 0, curr = 0;
    for EACH(V, A) {
        if (V.front() == 0) {
            curr++;
            continue;
        }
        int p = 0, pos = 1;
        for EACH(x, V) {
            if (abs(x) == 2) p++;
            if (x < 0) pos = 1 - pos;
        }
        if (pos) {
            if (p > mp) {
                mp = p;
                l = curr;
                r = n - (curr + V.size());
            }
        }
        else {
            int pl = 0, i = 0;
            for (; i < V.size(); i++) {
                if (abs(V[i]) == 2) pl++;
                if (V[i] < 0) break;
            }
            if (p - pl > mp) {
                mp = p - pl;
                l = curr + i + 1;
                r = n - (curr + V.size());
            }
            i = V.size() - 1, pl = 0;
            for (; i >= 0; i--) {
                if (abs(V[i]) == 2) pl++;
                if (V[i] < 0) break;
            }
            if (p - pl > mp) {
                mp = p - pl;
                l = curr;
                r = n - (curr + V.size()) + V.size() - i;
            }
        }
        curr += V.size();
    }
    cout << l << ' ' << r << '\n';
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