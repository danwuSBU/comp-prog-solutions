#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, a;
    cin >> t;
    while (t--) {
        cin >> n;
        map<ll, ll> counter;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            counter[a]++;
        }
        if ((sum * 2) % n != 0) {
            cout << 0 << '\n';
            continue;
        }
        ll target = sum * 2 / n;
        ll ret = 0;
        auto left = counter.begin(), right = --counter.end();
        while (left != right) {
            if (left->first + right->first == target) ret += left->second * right->second;
            if (left->first + right->first > target) right--;
            else left++;
        }
        if (target % 2 == 0 && counter.count(target / 2)) {
            ret += counter[target / 2] * (counter[target / 2] - 1) / 2;
        }
        cout << ret << '\n';
    }
    return 0;
}