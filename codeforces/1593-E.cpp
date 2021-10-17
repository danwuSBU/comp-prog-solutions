#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef set<int> si;
typedef queue<p> qi;
typedef vector<int> vi;
typedef vector<si> vvi;
 
int solve(vvi graph, qi frontier, vi deg, int k) {
    int counter = 0;
    while (frontier.size()) {
        p curr = frontier.front();
        frontier.pop();
        if (curr.second >= k) {
            return counter;
        }
        counter++;
        for (int x : graph[curr.first]) {
            if ((--deg[x]) == 1) frontier.push(p(x, curr.second + 1));
        }
    }
    return counter;
}
 
int main() {
    int t, n, k, u, v, m, s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vvi graph = vvi(n);
        vi degrees = vi(n, 0);
        m = n;
        n--;
        while (n--) {
            cin >> u >> v;
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
            degrees[u - 1]++;
            degrees[v - 1]++;
        }
        if (m <= 2) {
            if (k >= 1) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
            continue;
        }
        qi q = qi();
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 1) {
                q.push(p(i, 0));
            }
        }
        cout << m - solve(graph, q, degrees, k) << '\n';
    }
    return 0;
}