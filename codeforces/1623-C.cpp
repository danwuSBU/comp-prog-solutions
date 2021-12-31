#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

bool ok(vector<int> V, int k) {
    vector<int> W(V);
    for (int i = V.size() - 1; i >= 2; i--) {
        if (V[i] < k) return false;
        int diff = min(W[i], (V[i] - k)) / 3;
        V[i - 1] += diff;
        V[i - 2] += diff * 2;
    }
    return V[0] >= k && V[1] >= k;
}

void solve() {
    int n; cin >> n;
    vector<int> H(n); for (int &h : H) cin >> h;
    int low = *min_element(H.begin(), H.end()), high = *max_element(H.begin(), H.end()), mid, max = high;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (ok(H, mid) && (mid == max || !ok(H, mid + 1))) {
            cout << mid << '\n';
            return;
        }
        if (ok(H, mid)) low = mid + 1;
        else high = mid - 1;
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