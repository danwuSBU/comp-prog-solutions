#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, k;
    cin >> w >> h;
    vector<vector<int>> A(4);
    long long m = -1;
    for (int i = 0; i < 4; i++) {
        cin >> k;
        A[i] = vector<int>(k);
        for (int &j : A[i]) cin >> j;
        if (i < 2) {
            m = max(m, 1LL * (A[i].back() - A[i].front()) * h);
        }
        else {
            m = max(m, 1LL * (A[i].back() - A[i].front()) * w);
        }
    }
    cout << m << '\n';
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