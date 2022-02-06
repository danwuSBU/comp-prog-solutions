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
    int n, m, k; cin >> n >> m >> k;
    vector<int> hoz(n), ver(m);
    for EACH(h, hoz) cin >> h;
    for EACH(v, ver) cin >> v;
    vector<p> cors(k);
    for EACH(c, cors) cin >> c.first >> c.second;
    sort(cors.begin(), cors.end());
    int j = 0;
    ll pairs = 0;
    FOR(i, 0, n - 1) {
        int f = hoz[i], s = hoz[i + 1];
        map<int, int> counter;
        while (j < k && cors[j].first < s) {
            if (cors[j].first != f) {
                if (counter.count(cors[j].second)) counter[cors[j].second]++;
                else counter[cors[j].second] = 1;
            }
            j++;
        }
        vector<int> nums;
        for (p x : counter) nums.push_back(x.second);
        vector<int> prefix(nums); FOR(x, 1, prefix.size()) prefix[x] += prefix[x - 1];
        if (nums.size() > 1) {
            FOR(x, 0, nums.size() - 1) {
                pairs += 1LL * nums[x] * (prefix.back() - prefix[x]);
            }
        }
    }
    sort(cors.begin(), cors.end(), [] (p a, p b) {return tie(a.second, a.first) < tie(b.second, b.first);});
    j = 0;
    FOR(i, 0, m - 1) {
        int f = ver[i], s = ver[i + 1];
        map<int, int> counter;
        while (j < k && cors[j].second < s) {
            if (cors[j].second != f) {
                if (counter.count(cors[j].first)) counter[cors[j].first]++;
                else counter[cors[j].first] = 1;
            }
            j++;
        }
        vector<int> nums;
        for (p x : counter) nums.push_back(x.second);
        vector<int> prefix(nums); FOR(x, 1, prefix.size()) prefix[x] += prefix[x - 1];
        if (nums.size() > 1) {
            FOR(x, 0, nums.size() - 1) {
                pairs += 1LL * nums[x] * (prefix.back() - prefix[x]);
            }
        }
    }
    cout << pairs << '\n';
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