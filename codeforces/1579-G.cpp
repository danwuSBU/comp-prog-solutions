//unfinished
#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> p;
typedef map<int, p> mp;

int main() {
    int t, n, a;
    cin >> t;
    string s;
    int m = t;
    while (t--) {
        cin >> n;
        mp dp = mp();
        dp[0] = p(0, 0);
        while (n--) {
            cin >> a;
            mp nm = mp();
            for (auto const& [key, val] : dp) {
                if (key + a <= 1000) {
                    p temp = p(val.first, max(val.second, key + a));
                    if (!nm.count(key + a) || temp.second - temp.first <= nm[key + a].second - nm[key + a].first) nm[key + a] = temp;
                }
                if (key - a >= -1000) {
                    p temp = p(min(val.first, key - a), val.second);
                    if (!nm.count(key - a) || temp.second - temp.first <= nm[key - a].second - nm[key - a].first) nm[key - a] = temp;
                }
            }
            dp = nm;
        }
        int range = 2000;
        for (auto const& [key, val] : dp) {
            range = min(range, val.second - val.first);
        }
        s += to_string(range) + '\n';
    }
    cout << s;
    return 0;
}