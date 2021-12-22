#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
    string first = to_string(x1);
    string second = to_string(x2);
    while (first.length() < second.length()) {
        first += '0';
        p1--;
    }
    while (first.length() > second.length()) {
        second += '0';
        p2--;
    }
    if (p1 == p2) {
        if (first == second) cout << "=\n";
        else cout << ((first < second) ? "<\n" : ">\n");
    }
    else if (p1 < p2) cout << "<\n";
    else cout << ">\n";
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