#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, a, z, o;
    cin >> t;
    while (t--) {
        cin >> n;
        z = 0, o = 0;
        while (n--) {
            cin >> a;
            if (a == 0) z++;
            if (a == 1) o++;
        }
        cout << (1ll << z) * o << '\n';
    }
    return 0;
}