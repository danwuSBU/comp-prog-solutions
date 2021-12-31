#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n; p temp; cin >> n;
    vector<p> range(n);
    set<p> rangeset;
    for (p &r : range) {
        cin >> r.first >> r.second;
        rangeset.insert(r);
    }
    for (p &r : range) {
        for (int i = r.first; i <= r.second; i++) {
            bool ok = true;
            if (i > r.first && !rangeset.count(p(r.first, i - 1))) ok = false;
            if (i < r.second && !rangeset.count(p(i + 1, r.second))) ok = false;
            if (ok) {
                cout << r.first << ' ' << r.second << ' ' << i << '\n';
                break;
            }
        }
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