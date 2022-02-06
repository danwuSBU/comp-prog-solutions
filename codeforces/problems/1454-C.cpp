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
            cin >> a;
            v.push_back(a);            
        }
        auto last = unique(v.begin(), v.end());
        v.erase(last, v.end());
        if (v.size() == 1) cout << 0 << '\n';
        else {
            map<int, int> m = map<int, int>();
            for (int x : v) {
                if (m.count(x)) m[x]++;
                else m[x] = 1;
            }
            m[v.front()]--; m[v.back()]--;
            int minimum = INT32_MAX;
            for (const auto& [a, b] : m) {
                minimum = min(minimum, b + 1);
            }
            cout << minimum << '\n';
        }
    }
    return 0;
}