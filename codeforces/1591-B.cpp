#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    vector<int> A(n); 
    for (int &a : A) cin >> a;
    int changes = 0, beat = A.back();
    for (int i = A.size() - 2; i >= 0; i--) {
        if (A[i] > beat) {
            changes++;
            beat = A[i];
        }
    }
    cout << changes <<'\n';
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