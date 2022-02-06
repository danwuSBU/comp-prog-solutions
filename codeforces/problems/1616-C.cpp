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
    int minimum = n - 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int changes = 0;
            for (int k = 0; k < n; k++) {
                if ((A[j] - A[i]) * (k - i) != (A[k] - A[i]) * (j - i)) changes++;
            }
            minimum = min(changes, minimum);
        }
    }
    cout << minimum << '\n';
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