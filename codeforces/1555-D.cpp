#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l, r; string s;
    cin >> n >> m >> s;
    vector<string> vs = {"abc", "acb", "bca", "bac", "cab", "cba"};
    vector<vector<int>> v(6, vector<int>(n + 1, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] != vs[i][j % 3]) v[i][j + 1] = v[i][j] + 1;
            else v[i][j + 1] = v[i][j];
        }
    }
    while (m--) {
        cin >> l >> r;
        int best = INT32_MAX;
        for (int i = 0; i < 6; i++) {
            best = min(best, v[i][r] - v[i][l - 1]);
        }
        cout << best << '\n';
    }
    return 0;
}