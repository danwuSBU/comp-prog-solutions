//accepted on G++14
#include <iostream>
using namespace std;
int t, n, m, k;

int main() {
    cin >> t;
    string s;
    while (t--) {
        cin >> n, cin >> m, cin >> k;
        char c[n][m] = {{0}};
        char d[n][m] = {{0}};
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '*' && j + k < m && j - k >= 0 && i - k >= 0) {
                    bool possible = true;
                    for (int x = 0; x <= k; x++) {
                        if (c[i - x][j - x] != '*') possible = false;
                        if (c[i - x][j + x] != '*') possible = false;
                    }
                    if (possible) {
                        for (int x = 0; i - x >= 0 && j + x < m && j - x >= 0; x++) {
                            if (c[i - x][j - x] != '*') break;
                            if (c[i - x][j + x] != '*') break;
                            d[i - x][j - x] = '*';
                            d[i - x][j + x] = '*';
                        }
                    }
                }
            }
        }
        bool ret = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '*' && d[i][j] != '*') ret = false;
            }
        }
        if (ret) s += "YES\n";
        else s += "NO\n";
    }
    cout << s;
    return 0;
}