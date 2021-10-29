#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x = 0, q, a, b;
    cin >> n >> m;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    int B[m + 1] = {};
    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (A[i - 1][j] == 'X' && A[i][j - 1] == 'X') {
                B[j + 1] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < m + 1; i++) {
        B[i] += B[i - 1];
    }
    while (q--) {
        cin >> a >> b;
        if (B[b] - B[a]) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}