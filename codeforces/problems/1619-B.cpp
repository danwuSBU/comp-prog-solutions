#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int a = (int) sqrt(n);
    int b = (int) cbrt(n);
    int c = (int) sqrt(cbrt(n));
    cout << a + b - c << '\n';
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
