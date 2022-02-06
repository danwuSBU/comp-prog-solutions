#include <bits/stdc++.h>
using namespace std;

long long findNumber(int k, int n) {
    if (n <= k) {
        return n * 1LL * (n + 1) / 2;
    }
    long long total = k * 1LL * (k + 1) / 2 + k * 1LL * (k - 1) / 2;
    int m = k - (n - k);
    return total - m * 1LL * (m - 1) / 2;
}

void solve() {
    long long x; int k; cin >> k >> x;
    int left = 1, right = 2 * k - 1;
    if (k == 1 || x == 1) {
        cout << "1\n";
        return;
    }
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        long long s = findNumber(k, mid), t;
        if (mid < k) t = s + mid + 1;
        else t = s + (k - 1 - (mid - k));
        if (s < x && (t >= x || s == t)) {
            if (s == t) cout << mid << '\n';
            else cout << mid + 1 << '\n';
            return;
        }
        if (s >= x) right = mid - 1;
        else left = mid + 1;
    }
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