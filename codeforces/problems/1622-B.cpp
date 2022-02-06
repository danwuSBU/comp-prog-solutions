#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, double> pd;
const ll mod=1000000007;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int &a : A) cin >> a;
    string s; cin >> s;
    vector<int> X, Y;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') X.push_back(A[i]);
        else Y.push_back(A[i]);
    }
    vector<int> XX(X), YY(Y);
    sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
    X.insert(X.end(), Y.begin(), Y.end());
    unordered_map<int, int> B;
    for (int i = 0; i < X.size(); i++) B[X[i]] = i + 1;
    int x = 0, y = 0;
    for (char c : s) {
        if (c == '0') cout << B[XX[x++]] << ' ';
        else cout << B[YY[y++]] << ' ';
    }
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