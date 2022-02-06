#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c = 1; cin >> n;
    if (n % 2) {
        if (n / 2 % 2 == 0) cout << (n - 1) / 2 - 1 << ' ' << (n - 1) / 2 + 1 << " 1\n";
        else cout << (n - 1) / 2 - 2 << ' ' << (n - 1) / 2 + 2 << " 1\n";
    }
    else {
        cout << n - 3 << " 2 1\n";
    }
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