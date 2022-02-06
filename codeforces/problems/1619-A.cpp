#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    cout << (s.length() % 2 == 0 && (s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length() / 2)) ? "YES\n" : "NO\n");
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