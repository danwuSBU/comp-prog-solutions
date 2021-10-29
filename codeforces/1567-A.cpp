#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string s;
    cin >> t; while (t--) {
        cin >> n >> s;
        string out = "";
        for (auto &ch : s) {
            if (ch == 'U') out += 'D';
            else if (ch == 'D') out += 'U';
            else out += ch;
        }
        cout << out << '\n';
    }
    return 0;
}