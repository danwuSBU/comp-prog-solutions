#include <bits/stdc++.h>
using namespace std;

// subtree sums
unordered_set<int> visited;
vector<int> values;
vector<unordered_set<int>> graph;
int sum(int node) {
    visited.insert(node);
    int z = values[node];
    for (int y : graph[node]) {
        if (visited.count(y)) continue;
        int child = sum(y);
        z += child;
    }
    return z;
}