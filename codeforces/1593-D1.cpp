#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t, n, a;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v = vector<int>();
        int mi = INT32_MAX, ma = INT32_MIN;
        while (n--) {
            cin >> a;
            v.push_back(a);
            mi = min(mi, a);
            ma = max(ma, a);
        }
        if (mi == ma) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> cand = vector<int>();
        for (int i = 1; i <= sqrt(ma - mi); i++) {
            if ((ma - mi) % i == 0) {
                cand.push_back(i);
                cand.push_back((ma - mi) / i);
            }
        }
        int ret = 1;
        for (int x : cand) {
            int mod = v[0] % x;
            if (mod < 0) mod += x;
            int yes = true;
            for (int y : v) {
                if (y % x != mod && (y % x) + x != mod) {
                    yes = false;
                    break;
                }
            }
            if (yes) ret = max(ret, x);
        }
        cout << ret << '\n';
    }
    return 0;
}