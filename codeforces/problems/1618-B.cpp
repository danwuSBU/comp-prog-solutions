#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> A(n - 2);
    for (auto &a : A) cin >> a;
    bool done = false; string start = A.front();
    for (int i = 0; i < n - 3; i++) {
        if (A[i].back() != A[i + 1].front() && !done) {
            start += A[i + 1].front();
            done = true;
        }
        start += A[i + 1].back();
    }
    if (!done) start += 'a';
    cout << start << '\n';
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