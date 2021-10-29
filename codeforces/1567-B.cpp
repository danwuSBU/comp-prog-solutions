#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b, x = 0;
    int A[300002] = {}; for (int i = 0; i < 300002; i++) {
        x ^= i;
        A[i] = x;
    }
    cin >> t; while (t--) {
        cin >> a >> b;
        x = A[a - 1];
        if (x == b) cout << a << '\n';
        else if ((x ^ b) == a) cout << a + 2 << '\n';
        else cout << a + 1 << '\n';
    }
    return 0;
}