#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, a, b, c;
    cin >> t; while (t--) {
        cin >> n >> m;
        unordered_set<int> s = unordered_set<int>();
        while (m--) {
            cin >> a >> b >> c;
            s.insert(b);
        }
        for (int i = 1; i <= n; i++) {
            if (!s.count(i)) {
                for (int j = 1; j <= n; j++) {
                    if (j != i) cout << i << ' ' << j << '\n';
                }
                break;
            }
        }
    }
    return 0;
}