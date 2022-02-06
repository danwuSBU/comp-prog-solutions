#include <bits/stdc++.h>
using namespace std;

bool subsolve(string str, string q) {
    int index = str.find(q);
    if (index == string::npos || index > 0 && str.back() == '0') return false;
    for (int i = 0; i < index; i++) {
        if (str[i] == '0') return false;
    }
    for (int i = index + q.length(); i < str.length(); i++) {
        if (str[i] == '0') return false;
    }
    return true;
}

void solve() {
    long long x, y; cin >> x >> y;
    string xb = bitset<64>(x).to_string();
    xb.erase(0, xb.find_first_not_of('0'));
    string yb = bitset<64>(y).to_string();
    yb.erase(0, yb.find_first_not_of('0'));

    string xb1(xb), xb2(xb);
    reverse(xb1.begin(), xb1.end());
    xb1.erase(0, xb1.find_first_not_of('0'));
    xb2 += '1';
    reverse(xb2.begin(), xb2.end());

    string xb3(xb1), xb4(xb2);
    reverse(xb3.begin(), xb3.end());
    reverse(xb4.begin(), xb4.end());
    if (subsolve(yb, xb1) || subsolve(yb, xb2) || subsolve(yb, xb3) || subsolve(yb, xb4) || x == y) cout << "YES";
    else cout << "NO";
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}