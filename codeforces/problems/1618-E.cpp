#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> B(n);
    long long total = 0;
    for (auto &b : B) {
        cin >> b;
        total += b;
    }
    long long triangle = 1LL * n * (n + 1) / 2;
    if (total % triangle != 0) {
        cout << "NO\n";
        return;
    }
    long long sum = total / triangle;
    B.push_back(B.front());
    for (int i = 0; i < n; i++) {
        B[i] = B[i] - B[i + 1] + sum;
        if (B[i] % n != 0 || B[i] <= 0) {
            cout << "NO\n";
            return;
        }
        B[i] = B[i] / n;
    }
    B.pop_back();
    cout << "YES\n";
    cout << B.back() << ' ';
    B.pop_back();
    for (auto &b : B) {
        cout << b << ' ';
    }
    cout << '\n';
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