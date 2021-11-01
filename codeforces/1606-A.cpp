#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; string s; while (t--) {
        cin >> s; int ab = 0, ba = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') ab++;
            if (s[i] == 'b' && s[i + 1] == 'a') ba++;
        }
        if (ab == ba) cout << s << '\n';
        else {
            if (ab > ba) {
                if (s[s.length() - 2] == 'b' && s[s.length() - 1] == 'b') {
                    cout << s.substr(0, s.length() - 1) + 'a' << '\n';
                }
                else cout << s.substr(0, s.length() - 1) + 'a' << '\n';
            }
            else {
                if (s[s.length() - 2] == 'a' && s[s.length() - 1] == 'a') {
                    cout << s.substr(0, s.length() - 1) + 'b' << '\n';
                }
                else cout << s.substr(0, s.length() - 1) + 'b' << '\n';
            }
        }
    }
    return 0;
}