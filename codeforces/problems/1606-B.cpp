#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, k, hours, x;
    cin >> t; while (t--) {
        cin >> n >> k;
        n--; hours = 0;
        x = 1; while (x < k) {
            n -= x;
            x <<= 1;
            hours++;
            if (n <= 0) break;
        }
        if (n <= 0) cout << hours << '\n';
        else {
            hours += n / k;
            if (n % k != 0) hours++;
            cout << hours << '\n';
        }
    }
    return 0;
}