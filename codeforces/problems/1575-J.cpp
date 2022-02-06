#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, a, c;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    while (k--) {
        cin >> c;
        int x = 0, y = c - 1;
        while (x != n - 1 || v[x][y] != 2) {
            int temp = v[x][y];
            v[x][y] = 2;
            if (temp == 1) y++;
            else if (temp == 2) x++;
            else y--;
        }
        cout << y + 1 << ' ';
    }
    return 0;
}