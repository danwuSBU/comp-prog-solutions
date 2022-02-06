#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;

ll inf32 = 1e18;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n, x; cin >> n;
    vector<int> A(n); for (int &a : A) cin >> a;
    cin >> x;
    for (int &a : A) a -= x;
    int ret = 0; ll s = inf32;
    for (int &a : A) {
        s += a;
        if (s < 0) s = inf32;
        else {
            ret++;
            s = min(s, (ll) a);
        }
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