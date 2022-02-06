#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q, a, x, y, index = 0; cin >> q;
    vector<vector<int>> A(500005, vector<int>());
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            A[x].push_back(index++);
        }
        else {
            cin >> x >> y;
            if (x == y) continue;
            vector<int> &lx = A[x], &ly = A[y];
            if (A[x].size() > A[y].size()) {
                lx.swap(ly);
            }
            ly.insert(ly.end(), lx.begin(), lx.end());
            lx.clear();
        }
    }
    vector<int> res(index);
    for (int i = 0; i < A.size(); i++) {
        for (int x : A[i]) {
            res[x] = i;
        }
    }
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}