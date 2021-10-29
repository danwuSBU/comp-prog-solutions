#include <bits/stdc++.h>
using namespace std;

vector<int> transform(vector<int>& v) {
    unordered_map<int, int> m = unordered_map<int, int>();
    for (int i : v) {
        if (m.count(i)) m[i]++;
        else m[i] = 1;
    }
    vector<int> ret = vector<int>();
    for (int i = 0; i < v.size(); i++) {
        ret.push_back(m[v[i]]);
    }
    return ret;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a, q, x, k;
    cin >> t; while (t--) {
        vector<vector<int>> v = vector<vector<int>>();
        v.push_back(vector<int>());
        cin >> n; while (n--) {
            cin >> a;
            v[0].push_back(a);
        }
        while (true) {
            vector<int> vn = transform(v.back());
            if (vn == v.back()) break;
            v.push_back(vn);
        }
        cin >> q; while (q--) {
            cin >> x >> k;
            cout << v[min((int) v.size() - 1, k)][x - 1] << '\n';
        }
    }
    return 0;
}