#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n, m, rb, cb, rd, cd, dr = 1, dc = 1, t = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int x = 0, y = 0;
    if (rb > rd) x = 2 * (n - rb) + rb - rd;
    else x = rd - rb;
    if (cb > cd) y = 2 * (m - cb) + cb - cd;
    else y = cd - cb;
    cout << min(x, y) << '\n';
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