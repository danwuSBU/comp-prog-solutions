#define interactive 1

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define ROF(i,a,b) for (ll i = (b) - 1; i >= (a); --i)
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

// preprocess //
void prepare() {

}
// preprocess //

vector<vector<int>> graph;
map<int, int> parents;
set<int> visited;
void set_parents(int node, int prev) {
    if (visited.count(node)) return;
    visited.insert(node);
    parents[node] = prev;
    for EACH(v, graph[node]) set_parents(v, node);
}
map<p, pl> cache;
pl recurse(int node, int k) {
    if (cache.count(p(node, k))) return cache[p(node, k)];
    ll m = k, s = (k) ? graph[node].size() : 1;
    for EACH(v, graph[node]) {
        if (v == parents[node]) continue;
        pl res = recurse(v, 0);
        if (!k) {
            pl res2 = recurse(v, 1);
            if (res.first < res2.first || (res.first == res2.first && res2.second < res.second)) res.swap(res2);
        }
        m += res.first; s += res.second;
    }
    cache[p(node, k)] = pl(m, s);
    return pl(m, s);
}
void report(int node, pl value, vector<int> &assignments) {
    if (cache[p(node, 0)] == value) {
        for EACH(v, graph[node]) {
            if (v == parents[node]) continue;
            pl res = cache[p(v, 0)], res2 = cache[p(v, 1)];
            if (res.first < res2.first || (res.first == res2.first && res2.second < res.second)) res.swap(res2);
            report(v, res, assignments);
        }
    } 
    else {
        assignments[node] = graph[node].size();
        for EACH(v, graph[node]) {
            if (v == parents[node]) continue;
            report(v, cache[p(v, 0)], assignments);
        }
    }
}

void solve() {
    int n; cin >> n;
    graph = vector<vector<int>>(n, vector<int>());
    REP(n - 1) {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }
    set_parents(0, -1);
    pl res1 = recurse(0, 0);
    map<p, pl> c1(cache);
    pl res2 = recurse(0, 1);
    int x = 0;
    cache.swap(c1);
    if (res1.first < res2.first || (res1.first == res2.first && res2.second < res1.second)) {
        res1.swap(res2);
        c1.swap(cache);
        x = 1;
    }
    vector<int> assignments(n, 1);
    report(0, cache[p(0, x)], assignments);
    cout << res1.first << ' ' << res1.second << '\n';
    output_vector(assignments);
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