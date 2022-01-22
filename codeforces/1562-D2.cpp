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

void bfs(deque<p> frontier, vector<vector<int>> &graph, vector<int> &dists) {
    set<int> visited;
    while (frontier.size()) {
        int v = frontier.front().first, d = frontier.front().second;
        frontier.pop_front();
        if (visited.count(v)) continue;
        visited.insert(v);
        dists[v] = d;
        for EACH(a, graph[v]) {
            frontier.emplace_back(a, d + 1);
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> prefix(n, 0);
    if (s[0] == '-') prefix[0] = -1;
    else prefix[0] = 1;
    FOR(i, 1, n) {
        if (i % 2 == 0) {
            if (s[i] == '-') prefix[i] = prefix[i - 1] - 1;
            else prefix[i] = prefix[i - 1] + 1;
        }
        else {
            if (s[i] == '+') prefix[i] = prefix[i - 1] - 1;
            else prefix[i] = prefix[i - 1] + 1;
        }
    }
    map<int, vector<int>> buckets;
    for (int i = 0; i < n; i++) {
        if (buckets.count(prefix[i])) buckets[prefix[i]].push_back(i);
        else buckets[prefix[i]] = {i};
    }
    auto remove_rod = [&] (int le, int re) {
        int sum = (le == 0) ? prefix[re] : prefix[re] - prefix[le - 1], mid, target;
        if (sum > 0) {
            target = (le == 0) ? sum / 2 + 1 : sum / 2 + 1 + prefix[le - 1];
        }
        else {
            target = (le == 0) ? sum / 2 - 1 : sum / 2 - 1 + prefix[le - 1];
        }
        vector<int> &bucket = buckets[target];
        return *lower_bound(bucket.begin(), bucket.end(), le) + 1;
    };
    REP(q) {
        int l, r, pp; cin >> l >> r;
        l--, r--;
        if (l == 0) {
            pp = prefix[r];
        } 
        else {
            pp = prefix[r] - prefix[l - 1];
        }
        if (pp == 0) cout << "0\n";
        else if ((r - l) % 2 == 0) {
            cout << "1\n" << remove_rod(l, r) << '\n';
        }
        else {
            cout << "2\n" << l + 1 << ' ' << remove_rod(l + 1, r) << '\n';
        }
    }
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