#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ret = 0; cin >> n;
    vector<int> A(n);
    for (auto &a : A) cin >> a;
    set<int> u;
    for (int i = 1; i < n + 1; i++) u.insert(i);
    vector<int> B;
    for (auto a : A) {
        if (u.count(a)) u.erase(a);
        else B.push_back(a);
    }
    sort(B.begin(), B.end());
    auto it = u.begin();
    for (int i = 0; i < B.size(); i++) {
        if (*it == B[i]) {
            it++;
            continue;
        }
        if (*it > B[i] || B[i] - *it <= *it) {
            cout << "-1\n";
            return;
        }
        it++;
        ret++;
    }
    cout << ret << "\n";
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