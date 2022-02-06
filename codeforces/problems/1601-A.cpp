#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
   if (b == 0) return a;
   a %= b;
   return gcd(b, a);
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a, r;
    cin >> t; while (t--) {
        int A[30] = {}; cin >> n; for (int i = 0; i < n; i++) {
            cin >> a;
            for (int i = 0; i < 30; i++) {
                if (a & 1) {
                    A[i]++;
                }
                a >>= 1;
            }
        }
        r = 0; for (int i : A) {
            r = gcd(r, i);
        }
        for (int i = 1; i <= n; i++) {
            if (r % i == 0) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}