#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n; string s;
    cin >> t; while (t--) {
        cin >> n >> s;
        int ones = 0;
        for (char i : s) if (i == '1') ones++;
        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1' && i < s.length() - ones) v.push_back(i);
            if (s[i] == '0' && i >= s.length() - ones) v.push_back(i);
        }
        if (v.size() == 0) cout << "0\n";
        else {
            cout << "1\n" << v.size() << ' ';
            for (int i : v) cout << i + 1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}