#include <bits/stdc++.h>
using namespace std;

struct building
{
    int trips;
    int index;
};

void solve() {
    int n; cin >> n;
    vector<building> A(n);
    for (int i = 0; i < n; i++) {
        A[i].index = i;
        cin >> A[i].trips;
    }
    sort(A.begin(), A.end(), [](building a, building b) {return a.trips > b.trips;});
    vector<int> results(n);
    long long distance = 0;
    for (int i = 0; i < n; i += 2) {
        results[A[i].index] = i / 2 + 1; distance += 1LL * (i / 2 + 1) * 2 * A[i].trips;
        if (i + 1 < n) {results[A[i + 1].index] = - (i / 2 + 1); distance += 1LL * (i / 2 + 1) * 2 * A[i + 1].trips;}
    }
    cout << distance << '\n' << "0 ";
    for (int a : results) {
        cout << a << " ";
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