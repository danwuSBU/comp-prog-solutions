#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int &a : A) cin >> a;
    int ret = INT32_MAX;
    for (int ones = 0; ones <= 2; ones++) {
        for (int twos = 0; twos <= 2; twos++) {
            unordered_set<int> powersum;
            powersum.insert(0);
            vector<int> numbers;
            for (int i = 0; i < ones; i++) numbers.push_back(1);
            for (int i = 0; i < twos; i++) numbers.push_back(2);
            while (numbers.size()) {
                int n = numbers.back();
                numbers.pop_back();
                for (int p : powersum) {
                    powersum.insert(n + p);
                }
            }
            int maxnum = 0;
            for (int a : A) {
                if (a >= 3 && powersum.count(a - (a / 3 * 3) + 3)) maxnum = max(maxnum, a / 3 - 1 + ones + twos);
                else if (powersum.count(a - (a / 3 * 3))) maxnum = max(maxnum, a / 3 + ones + twos);
                else {
                    maxnum = 1e9;
                    break;
                }
            }
            ret = min(ret, maxnum);
        }
    }
    cout << ret << '\n';
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}