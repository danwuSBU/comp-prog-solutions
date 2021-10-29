#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t; while (t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            cout << i << ' ';
        }
        cout << 1 << '\n';
    }
    return 0;
}