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
    int n, k, v, u; cin >> n >> k;
    deque<p> F(k); for EACH(f, F) {
        cin >> f.first;
        f.second = 0;
    }
    vector<int> L; vector<vector<int>> G(n + 1, vector<int>());
    REP(n - 1) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    FOR(i, 0, n + 1) {
        if (G[i].size() == 1 && i != 1) L.push_back(i);
    }
    vector<int> Ldist(n + 1, BIG32);
    vector<int> Rdist(n + 1, BIG32);
    bfs(F, G, Ldist);
    bfs(deque<p>{p(1, 0)}, G, Rdist);
    for EACH(f, L) {
        if (Ldist[f] > Rdist[f]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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