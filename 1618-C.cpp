#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<unsigned long long> A(n);
    for (auto &a : A) cin >> a;
    unsigned long long l = A.front(); bool ok = true;
    for (int i = 0; i < n; i += 2) {
        l = __detail::__gcd(l, A[i]);
    }
    for (int i = 1; i < n; i += 2) {
        if (A[i] % l == 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << l << '\n';
        return;
    }
    l = A[1]; ok = true;
    for (int i = 1; i < n; i += 2) {
        l = __detail::__gcd(l, A[i]);
    }
    for (int i = 0; i < n; i += 2) {
        if (A[i] % l == 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << l << '\n';
        return;
    }
    cout << "0\n";
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