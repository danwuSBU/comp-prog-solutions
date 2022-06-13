#include <bits/stdc++.h>
using namespace std;

// subtree sizes
int get_st_sizes(vector<int> &sizes, set<int> &visited, vector<vector<int>> &graph, int node) {
    visited.insert(node);
    int s = 1;
    for (int y : graph[node]) {
        if (visited.count(y)) continue;
        s += get_st_sizes(sizes, visited, graph, y);
    }
    sizes[node] = s;
    return s;
}