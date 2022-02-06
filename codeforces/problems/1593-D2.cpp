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
        sort(v.begin(), v.end());
        unordered_map<int, int> m = unordered_map<int, int>();
        bool large = false;
        for (int x : v) {
            if (m.count(x)) {
                m[x]++; if (m[x] == v.size() / 2) {large = true; break;}
            }
            else m[x] = 1;
        }
        if (large) {
            cout << "-1" << '\n';
            continue;
        }
        int k = 1; unordered_set<int> t = unordered_set<int>();
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                for (int x = 2; x <= sqrt(v[j] - v[i]); x++) {
                    if ((v[j] - v[i]) % x == 0) {
                        t.insert(x);
                        t.insert((v[j] - v[i]) / x);
                    }
                }
                t.insert(v[j] - v[i]);
            }
        }
        for (int x : t) {
            if (x <= k) continue;
            int count = 0;
            int A[x] = {};
            for (int y : v) {
                y %= x; y += x; y %= x;
                A[y]++;
                if (A[y] == v.size() / 2) k = x;
            }
        }
        cout << k << '\n';
    }
    return 0;
}