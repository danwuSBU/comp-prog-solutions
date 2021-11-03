#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t; while (t--) {
        cin >> n; vector<int> v = vector<int>(); while (n--) {
            cin >> a; v.push_back(a);
        }
        sort(v.begin(), v.end());
        if (v.size() == 1) cout << v.back() << '\n';
        else {
            int maxgap = v.front();
            for (int i = 0; i < v.size() - 1; i++) {
                maxgap = max(maxgap, v[i + 1] - v[i]);
            }
            cout << maxgap << '\n';
        }
    }
    return 0;
}