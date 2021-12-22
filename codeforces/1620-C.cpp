#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k, x; cin >> n >> k >> x; x--;
    string s; cin >> s;
    vector<int> base;
    int running = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') running++;
        else if (running > 0) {
            base.push_back(running);
            running = 0;
        }
    }
    if (running > 0) {
        base.push_back(running);
    }
    string ns = string{s[0]};
    for (int i = 1; i < s.length(); i++) if (s[i] != '*' || s[i - 1] != '*') ns += string{s[i]};
    vector<int> values(base.size(), 0);
    for (int i = base.size() - 1; i >= 0; i--) {
        if (x > 0) {
            values[i] = x % (k * base[i] + 1);
            x /= k * base[i] + 1;
        }
    }
    int i = 0;
    string ret = "";
    for (char x : ns) {
        if (x == '*') {
            ret += string(values[i], 'b');
            i++;
        }
        else ret += string{x};
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