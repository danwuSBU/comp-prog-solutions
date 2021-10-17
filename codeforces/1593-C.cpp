#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, k, a;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v = vector<int>();
        while (k--) {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), greater<int>());
        int sum = 0, count = 0;
        for (int x : v) {
            sum += n - x;
            count++;
            if (sum >= n) {
                count--;
                break;
            }
        }
        cout << count << '\n';
    }
    return 0;
}