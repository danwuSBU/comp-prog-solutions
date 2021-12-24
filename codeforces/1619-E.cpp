#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a; cin >> n;
    vector<int> A(n + 1, 0);
    vector<long long> MEX(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        A[a]++;
    }
    int CMEX = 0;
    while (A[CMEX]) CMEX++;
    MEX[CMEX] = 0;
    vector<int> free;
    for (int i = 0; i < CMEX; i++) {
        MEX[i] = A[i];
        for (int j = 0; j < A[i] - 1; j++) free.push_back(i);
    }
    long long moves = 0;
    for (int i = CMEX; i < n; i++) {
        if (!A[i]) {
            if (!free.size()) break;
            moves += i - free.back(); free.pop_back();
        }
        else {
            for (int j = 0; j < A[i] - 1; j++) free.push_back(i);
        }
        if (i < n) MEX[i + 1] = moves + A[i + 1];
        else MEX[i + 1] = moves;
    }
    for (long long a : MEX) cout << a << ' ';
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