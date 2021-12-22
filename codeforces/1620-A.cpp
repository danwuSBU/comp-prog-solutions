#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = count(s.begin(), s.end(), 'N');
    if (n == 1) cout << "NO\n";
    else cout << "YES\n";
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