#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, x, c, d; cin >> a >> b >> x;
    c = min(a, b), d = max(a, b);
    while (c && d) {
        if (x <= d && x % c == d % c) {
            cout << "YES\n";
            return;
        }
        d = d % c;
        swap(c, d);
    }
    cout << "NO\n";
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