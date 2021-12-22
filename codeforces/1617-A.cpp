#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t, a, b;
    cin >> s >> t;
    string ss(s); sort(ss.begin(), ss.end());
    string tt(t);
    if (tt == "abc" && ss[0] == 'a') {
        a = "";
        for (int i = 0; i < ss.length(); i++) {
            if (ss[i] == 'b') {
                a += 'c';
            }
            else if (ss[i] == 'c') {
                a += 'b';
            }
            else {
                a += ss[i];
            }
        }
        b = "";
        sort(a.begin(), a.end());
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'b') {
                b += 'c';
            }
            else if (a[i] == 'c') {
                b += 'b';
            }
            else {
                b += a[i];
            }
        }
    }
    else {
        b = ss;
    }
    cout << b << '\n';
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