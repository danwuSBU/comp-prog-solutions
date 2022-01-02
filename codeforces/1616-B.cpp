#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n; string s; cin >> n >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1] || s[i] == s[0]) {
            string r(s.substr(0, i));
            reverse(r.begin(), r.end());
            cout << s.substr(0, i) + r << '\n';
            return;
        }
    }
    string r(s);
    reverse(r.begin(), r.end());
    cout << s + r << '\n';
    return;
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