#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, f = 1; cin >> n;
    vector<int> anc(n), assignments(n, 0), sums(n, 0); set<int> s; vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> anc[i];
        graph[anc[i] - 1].push_back(i);
        if (i == anc[i] - 1) s.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!s.count(a - 1)) {
            f = 0;
        }
        if (assignments[anc[a - 1] - 1] != 0) assignments[a - 1] = i - sums[anc[a - 1] - 1];
        else assignments[a - 1] = i;
        sums[a - 1] = i;
        for (int x : graph[a - 1]) s.insert(x);
    }
    if (!f) {
        cout << "-1\n"; return;
    }
    for (int i : assignments) cout << i << ' ';
    cout << '\n';
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}