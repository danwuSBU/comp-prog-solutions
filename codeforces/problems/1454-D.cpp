#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n;
    cin >> t; while (t--) {
        cin >> n;
        long long m = n;
        int total = 1;
        vector<long long> v = vector<long long>{0, 0, n};
        for (long long i = 2; i <= (long long) sqrt(n); i++) {
            int curr = 0;
            while (n % (i * i) == 0) {
                curr += 1, n /= i;
                if (curr >= total) {
                    total = curr;
                    v[0] = curr;
                    v[1] = i;
                    v[2] = m / pow(i, curr);
                }
            }
        }
        cout << v[0] + 1 << '\n';
        for (int i = 0; i < v[0]; i++) {
            cout << v[1] << ' ';
        }
        cout << v[2] << '\n';
    }
    return 0;
}