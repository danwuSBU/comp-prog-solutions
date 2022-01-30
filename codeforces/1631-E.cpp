#define interactive 1

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
    int n; cin >> n;
    vector<int> A(n); for EACH(a, A) cin >> a;
    map<int, p> m;
    FOR(i, 0, n) {
        int &a = A[i];
        if (!m.count(a)) m[a] = p(i, 0);
        else m[a].second = i;
    }
    vector<p> intervals;
    for (const auto &[key, value] : m) {
        if (value.second && value.second - value.first > 1) {
            intervals.emplace_back(value.first , value.second);
        }
    }
    sort(intervals.begin(), intervals.end());
    if (intervals.size() == 0) {
        cout << "0\n";
        return;
    }
    vector<p> out{intervals[0]};
    int ret = 0;
    int i = 1;
    while (i < intervals.size()) {
        int maxstep = out.back().second;
        while (out.back().second >= intervals[i].first && i < intervals.size()) {
            maxstep = max(maxstep, intervals[i].second);
            i++;
        }
        if (maxstep == out.back().second) {
            if (i >= intervals.size()) continue;
            out.push_back(intervals[i++]);
        }
        else {
            out.back().second = maxstep;
            ret--;
        }
    }
    for EACH(i, out) {
        ret += i.second - i.first - 1;
    }
    cout << ret << '\n';
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