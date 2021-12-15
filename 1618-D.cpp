#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    int total = 0;
    for (int i = 0; i < n - 2 * k; i++) total += A[i];
    for (int i = n - 2 * k; i < n - k; i++) total += A[i] / A[i + k];
    cout << total << '\n';
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