#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, a; cin >> n >> k;
    vector<int> pos, neg;
    while (n--) {
        cin >> a;
        if (a > 0) pos.push_back(a);
        if (a < 0) neg.push_back(a);
    }
    long long total;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    if (pos.size() && neg.size()) {
        if (pos.back() > -neg.back()) {
            total = pos.back();
            for (int i = 0; i < k; i++) {
                if (pos.size()) pos.pop_back();
            }
        }
        else {
            total = -neg.back();
            for (int i = 0; i < k; i++) {
                if (neg.size()) neg.pop_back();
            }
        }
    }
    else if (neg.size()) {
        total = -neg.back();
        for (int i = 0; i < k; i++) {
            if (neg.size()) neg.pop_back();
        }
    }
    else if (pos.size()) {
        total = pos.back();
        for (int i = 0; i < k; i++) {
            if (pos.size()) pos.pop_back();
        }
    }
    else total = 0;

    while (pos.size() > 0) {
        total += 2 * pos.back();
        for (int i = 0; i < k; i++) {
            if (pos.size() > 0) pos.pop_back();
        }
    }
    while (neg.size() > 0) {
        total += 2 * -neg.back();
        for (int i = 0; i < k; i++) {
            if (neg.size() > 0) neg.pop_back();
        }
    }
    cout << total << '\n';
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