#include <bits/stdc++.h>
using namespace std;

long long bisect_left(vector<long long> v, long long x) {
    long long low = 0, high = v.size() - 1, mid;
    if (x > v.back()) return v.size();
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (v[mid] >= x && (mid == 0 || v[mid - 1] < x)) return mid;
        if (v[mid] >= x) high = mid - 1;
        else low = mid + 1;
    }
    return mid;
}

long long calculate(vector<long long> v, long long k, vector<long long> prefix) {
    int index = bisect_left(v, k);
    if (index == 0) return 1LL * (v.size() + 1) * k;
    return 1LL * (v.size() - index + 1) * k + prefix[index - 1];
}

vector<long long> prefix_sum(vector<long long> v) {
    for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    return v;
}

void solve() {
    int n; long long h;
    cin >> n >> h; vector<long long> A(n); vector<long long> B, C;
    for (auto &a : A) cin >> a;
    if (n == 1) {
        cout << h << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) B.push_back(A[i + 1] - A[i]);
    sort(B.begin(), B.end());
    C = prefix_sum(B);
    long long low = 0, high = h, mid;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (calculate(B, mid, C) >= h && (mid == 0 || calculate(B, mid - 1, C) < h)) {
            cout << mid << '\n';
            return;
        }
        if (calculate(B, mid, C) >= h) high = mid - 1;
        else low = mid + 1;
    }
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