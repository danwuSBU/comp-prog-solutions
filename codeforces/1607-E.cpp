#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m; string s;
    cin >> t; while (t--) {
        cin >> n >> m >> s;
        int maxh = n - 1, maxw = m - 1, N = 0, S = 0, W = 0, E = 0, x = 0, y = 0; bool ok = true;
        for (char c : s) {
            if (c == 'R') x++;
            if (c == 'L') x--;
            if (c == 'D') y++;
            if (c == 'U') y--;
            if (S - y > maxh || y - N > maxh){
                if (c == 'U') y++; if (c == 'D') y--;
                cout << 1 - N << ' ' << 1 - W << '\n'; ok = false; break;
            }
            if (E - x > maxw || x - W > maxw){
                if (c == 'L') x++; if (c == 'R') x--;
                cout << 1 - N << ' ' << 1 - W << '\n'; ok = false; break;
            }
            N = min(y, N), E = max(x, E), W = min(x, W), S = max(y, S);
        }
        if (ok) cout << 1 - N << ' ' << 1 - W << '\n';
    }
    return 0;
}