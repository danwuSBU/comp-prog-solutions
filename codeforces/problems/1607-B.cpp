#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, x, n, m, o;
    cin >> t; while (t--) {
        cin >> x >> n;
        if (n == 0) {
            cout << x << '\n';
            continue;
        }
        m = -1; o = n - 1;
        m -= 4 * (o / 4); o = o % 4;
        if (o == 1) m += n;
        if (o == 2) m += n + n - 1;
        if (o == 3) m += n - 3;
        if (x % 2) m *= -1;
        m += x;
        cout << m << '\n';
    }
    return 0;
}