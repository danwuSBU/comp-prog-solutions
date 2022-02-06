#include <bits/stdc++.h>
using namespace std;

unordered_set<int> visited;
vector<int> values;
vector<unordered_set<int>> graph;
bool changed; int x; pair<int, int> to_erase;

int dfs(int node) {
    visited.insert(node);
    int z = values[node];
    for (int y : graph[node]) {
        if (visited.count(y)) continue;
        int child = dfs(y);
        if (!changed && child == x) {
            changed = true; to_erase = pair<int, int>{node, y};
        }
        z ^= child;
    }
    return z;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, a, u, v;
    cin >> t; while (t--) {
        x = 0; cin >> n >> k; values.clear(); for (int i = 0; i < n; i++) {
            cin >> a;
            values.push_back(a);
            x ^= a;
        }
        graph = vector<unordered_set<int>>(n, unordered_set<int>()); while (--n) {
            cin >> u >> v;
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
        }
        if (x == 0) {
            cout << "YES" << '\n'; continue;
        }
        if (k == 2) {
            cout << "NO" << '\n'; continue;
        }
        visited.clear(); changed = false; dfs(0);
        if (changed) {
            visited.clear(); changed = false; graph[to_erase.first].erase(to_erase.second); graph[to_erase.second].erase(to_erase.first); dfs(0);
            if (changed) {
                cout << "YES" << '\n'; 
            }
            else cout << "NO" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}