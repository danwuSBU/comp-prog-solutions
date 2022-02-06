#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;

void solve() {
    int n; string s; cin >> n >> s;
    auto balanced = [](string x) -> bool {
        return count(x.begin(), x.end(), 'a') == count(x.begin(), x.end(), 'b');
    };
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (balanced(s.substr(i, j - i + 1))) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }
    cout << "-1 -1\n";
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