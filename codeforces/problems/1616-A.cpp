#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n; cin >> n;
    vector<int> A(n); for (int &a : A) cin >> a;
    sort(A.begin(), A.end());
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i - 1]) A[i] *= -1;
    }
    sort(A.begin(), A.end());
    auto last = unique(A.begin(), A.end());
    A.erase(last, A.end());
    cout << A.size() << '\n';
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