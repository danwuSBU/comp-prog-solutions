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

void solve() {
    int n; cin >> n;
    auto query = [] (int a, int b, int c) {
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int res; cin >> res;
        return res;
    };
    vector<p> curr{p(0, 0), p(1, 0), p(2, 0), p(3, 0)};
    auto process = [&] () {
        curr[0].second = query(curr[1].first, curr[2].first, curr[3].first);
        curr[1].second = query(curr[0].first, curr[2].first, curr[3].first);
        curr[2].second = query(curr[1].first, curr[0].first, curr[3].first);
        curr[3].second = query(curr[1].first, curr[2].first, curr[0].first);
        sort(curr.begin(), curr.end(), [] (p a, p b) {return a.second < b.second;});
    };
    process();
    int extra;
    for (int i = 4; i < n; i += 2) {
        if (i == 4) {
            extra = curr.back().first;
        }
        curr[2].first = i;
        curr[3].first = (i + 1 == n) ? extra : i + 1;
        process();
    }
    cout << "! " << curr[0].first + 1 << " " << curr[1].first + 1 << endl;
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