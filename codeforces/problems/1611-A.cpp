#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n; cin >> n;
    if ((n.back() - '0') % 2 == 0) {
        cout << "0\n";
        return;
    }
    if ((n.front() - '0') % 2 == 0) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n.length(); i++) {
        if ((n[i] - '0') % 2 == 0) {
            cout << "2\n";
            return;
        }
    }
    cout << "-1\n";
    return;
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