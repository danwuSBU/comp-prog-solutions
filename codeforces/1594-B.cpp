#include <iostream>
#include <bitset>
using namespace std;
long long t, n, a, b, r, p;
int mod = 1000000007;
int main() {
    cin >> t;
    string ret;
    while (t--) {
        cin >> a;
        cin >> b;
        bitset<64> bt(b);
        string s = bt.to_string();
        r = 0, p = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                r = (r + p) % mod;
            }
            p = (p * a) % mod;
        }
        ret += to_string(r) + '\n';
    }
    cout << ret;
    return 0;
}