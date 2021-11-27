#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int m = *max_element(nums.begin(), nums.end());
    if (nums.front() == m || nums.back() == m) {
        for (int i = n - 1; i >= 0; i--) cout << nums[i] << ' ';
    }
    else cout << "-1";
    cout << '\n';
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