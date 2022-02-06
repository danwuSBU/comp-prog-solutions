#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if ((x + y) % 2) cout << "-1 -1\n";
    else if (x % 2) {
        cout << x / 2 << ' ' << y / 2 + 1 << '\n';
    }
    else cout << x / 2 << ' ' << y / 2 << '\n';
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