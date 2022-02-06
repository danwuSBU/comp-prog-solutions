#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;
typedef pair<int, int> p;
int search(int n, int z, vector<vector<int>> v) {
    set<int> visited = set<int>();
    vector<int> colors = vector<int>(z, -1);
    int imposters = 0;
    for (int i = 1; i < n + 1; i++) { 
        if (visited.count(i)) continue;
        vector<p> stack = vector<p>();
        stack.push_back(p(i, 0));
        int c = 0, d = 0;
        while (stack.size()) {
            p curr = stack.back();
            stack.pop_back();
            if (visited.count(curr.first)) continue;
            colors[curr.first] = curr.second;
            visited.insert(curr.first);
            if (curr.first <= n) {
                if (curr.second) d++;
                else c++;
            }
            for (int x : v[curr.first]) {
                if (visited.count(x)) {
                    if (colors[x] == curr.second) {
                        return -1;
                    }
                }
                else {
                    stack.push_back(p(x, 1 - curr.second));
                }
            }
        }
        imposters += max(c, d);
    }
    return imposters;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, a, b;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> v = vector<vector<int>>(n + 1);
        int nn = n + 1;
        set<tuple<int, int, string>> edges = set<tuple<int, int, string>>();
        while (m--) {
            cin >> a;
            cin >> b;
            cin >> s;
            if (edges.count(tuple<int, int, string>(a, b, s))) continue;
            edges.insert(tuple<int, int, string>(a, b, s));
            if (s == "imposter") {
                v[a].push_back(b);
                v[b].push_back(a);
            }
            else {
                v.push_back(vector<int>());
                v[a].push_back(nn);
                v[nn].push_back(a);
                v[b].push_back(nn);
                v[nn].push_back(b);
                nn++;
            }
        }
        cout << search(n, nn, v) << '\n';
    }
    return 0;
}