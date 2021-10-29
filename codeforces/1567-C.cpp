#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; string n; cin >> t; while (t--) {
        cin >> n;
        int parity = n.length() % 2;
        int a = 0, b = 0;
        for (auto &ch : n) {
            if (parity % 2) a = a * 10 + (ch - '0');
            else b = b * 10 + (ch - '0');
            parity++;
        }
        cout << (a + 1) * (b + 1) - 2 << '\n';
    }
    return 0;
}