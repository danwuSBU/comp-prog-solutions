#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> V(7);
    for (auto &a : V) cin >> a;
    cout << V.front() << ' ' << V[1] << ' ' << V.back() - (V.front() + V[1]) << '\n';
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