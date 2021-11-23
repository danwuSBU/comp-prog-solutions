#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (a - b > 1 || (b > a && (a > n / 2 || n - b + 1 > n / 2)) || (a == b + 1 && b != n / 2)) cout << "-1\n";
    else {
        vector<int> v(n);
        v.front() = a; v.back() = b;
        int p = 1;
        for (int i = n; i > b; i--) {
            if (i != a) {
                v[p] = i;
                p++;
            }
        }
        int q = n - 2;
        for (int i = 1; i < a; i++) {
            if (i != b) {
                v[q] = i;
                q--;
            }
        }
        for (int i = a + 1; i < b; i++) {
            v[p] = i;
            p++;
        }
        for (int i : v) cout << i << ' ';
        cout << '\n';
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