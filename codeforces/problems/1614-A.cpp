#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, k, a; cin >> n >> l >> r >> k;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (l <= a && a <= r) {
            s.insert(a);
        }
    }
    int ret = 0;
    while (s.size() && *s.begin() <= k) {
        k -= *s.begin();
        ret++;
        s.erase(s.begin());
    }
    cout << ret << '\n';
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