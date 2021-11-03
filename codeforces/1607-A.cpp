#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; string s;
    cin >> t; while (t--) {
        cin >> s;
        unordered_map<int, int> m = unordered_map<int, int>();
        for (int i = 0; i < s.length(); i++) m[s[i]] = i;
        cin >> s; int total = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            total += abs(m[s[i]] - m[s[i + 1]]);
        }
        cout << total << '\n';
    }
    return 0;
}