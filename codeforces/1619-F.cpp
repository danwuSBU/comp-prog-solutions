#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int shift = n - n / m * (m - (n % m));
    vector<int> tables(m, n / m);
    for (int i = 0; i < n % m; i++) tables[i]++;
    int start = 0;
    for (int i = 0; i < k; i++) {
        for (int t : tables) {
            cout << t << ' ';
            while (t--) cout << (start++ % n) + 1 << ' ';
            cout << '\n';
        }
        start = (start + shift) % n;
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