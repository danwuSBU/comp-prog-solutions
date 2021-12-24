#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, s; cin >> a >> s;
    vector<int> result;
    int i = a.length() - 1, j = s.length() - 1;
    while (i >= 0 && j >= 0) {
        if (s[j] >= a[i]) {
            result.push_back(s[j] - a[i]);
            j--; i--;
        }
        else {
            if (j > 0 && s[j - 1] == '1') {
                result.push_back(10 + s[j] - a[i]);
                j -= 2; i--;
            }
            else {
                cout << "-1\n";
                return;
            }
        }
    }
    if (j < 0 && i >= 0) {
        cout << "-1\n";
        return;
    }
    while (j >= 0) {
        result.push_back(s[j] - 48);
        j--;
    }
    reverse(result.begin(), result.end());
    i = 0;
    while (result[i] == 0 && i < result.size()) i++;
    while (i < result.size()) {
        cout << result[i];
        i++;
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