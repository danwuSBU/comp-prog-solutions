#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, a; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    auto it = s.begin();
    int min = *it;
    it++;
    for (int i = 0; i < n / 2; i++) {
        cout << *it << ' ' << min << '\n';
        it++;
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