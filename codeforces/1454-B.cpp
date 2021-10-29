#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t; while (t--) {
        map<int, int> m = map<int, int>();
        vector<int> v = vector<int>();
        cin >> n; while (n--) {
            cin >> a;
            v.push_back(a);
            if (m.count(a)) m[a]++;
            else m[a] = 1;
        }
        int ret = INT32_MAX;
        for (const auto& [a, b] : m) {
            if (b == 1) ret = min(ret, a);
        }
        if (ret == INT32_MAX) cout << -1 << '\n';
        else {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == ret) cout << i + 1 << '\n';
            }
        }
    }
    return 0;
}