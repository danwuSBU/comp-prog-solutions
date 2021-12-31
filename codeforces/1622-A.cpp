#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, double> pd;
const ll mod=1000000007;

void solve() {
    vector<int> A(3);
    for (int &a : A) cin >> a;
    sort(A.begin(), A.end());
    if (A[0] + A[1] == A[2] || (A[0] == A[1] && A[2] % 2 == 0) || (A[1] == A[2] && A[0] % 2 == 0)) cout << "YES\n";
    else cout << "NO\n";
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