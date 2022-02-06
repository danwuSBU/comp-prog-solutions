#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, double> pd;
const ll mod=1000000007;

template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<int> A(n);
    for (int &a : A) cin >> a;
    ll total = accumulate(A.begin(), A.end(), 0LL);
    if (total <= k) {
        cout << "0\n";
        return;
    }
    sort(A.begin(), A.end());
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + A[i];
    ll best = 1e16, moves;
    if (A.size() == 1) {
        cout << A[0] - k << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        total = prefix[i] + A[0] * (n - i);
        moves = n - i;
        if (total > k) moves += ceil((double) (total - k) / (n - i + 1));
        best = min(best, moves);
    }
    cout << best << '\n';
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