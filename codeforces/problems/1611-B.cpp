#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    int diff = (b - a) / 2;
    if (diff > a) {
        cout << a << '\n'; return;
    }
    cout << (a - diff) / 2 + diff << '\n';
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