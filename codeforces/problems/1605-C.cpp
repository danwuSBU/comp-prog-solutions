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
        if (s.find("aa") != -1) cout << "2\n";
        else if (s.find("aba") != -1 || s.find("aca") != -1) cout << "3\n";
        else if (s.find("abca") != -1 || s.find("acba") != -1) cout << "4\n";
        else if (s.find("abbacca") != -1 || s.find("accabba") != -1) cout << "7\n";
        else cout << "-1\n";
    }
    return 0;
}