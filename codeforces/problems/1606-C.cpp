#include <bits/stdc++.h>
using namespace std;

long long power(int i, int p) {
    if (p == 0) return 1;
    while (--p > 0) i *= 10;
    return i;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, a;
    cin >> t; while (t--) {
        cin >> n >> k; long long total = 0; vector<int> v; while (n--) {
            cin >> a; v.push_back(a);
        }
        for (int i = 0; i < v.size() - 1; i++) {
            long long diff = power(10, v[i + 1] - v[i]) - 1;
            if (diff > k) {
                total += (k + 1) * power(10, v[i]); k = -1;
                break;
            }
            else {
                total += diff * power(10, v[i]); k -= diff;
            }
        }
        if (k >= 0) {
            total += (k + 1) * power(10, v.back());
        }
        cout << total << '\n';
    }
    return 0;
}