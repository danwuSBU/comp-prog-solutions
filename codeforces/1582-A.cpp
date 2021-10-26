#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        c = (c % 2) * 3;
        if (b && c) c = 1;
        if (b && !c) c = (b % 2) * 2;
        if (a) {
            if (a >= c) {
                c = (a - c) % 2;
            }
            else {
                c -= a;
            }
        }
        cout << c << '\n';
    }
    return 0;
}