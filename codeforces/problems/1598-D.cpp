#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int, int> um;
typedef pair<int, int> p;
typedef vector<p> vp;
typedef unsigned long long ll;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, a, b, total;
    cin >> t;
    while (t--) {
        cin >> n;
        um topics = um(), diffs = um();
        total = n * 1LL * (n - 1) * (n - 2) / 6;
        vp list = vp();
        while (n--) {
            cin >> a >> b;
            if (topics.count(a)) topics[a]++;
            else topics[a] = 1;
            if (diffs.count(b)) diffs[b]++;
            else diffs[b] = 1;
            list.emplace_back(a, b);
        }
        for (auto const& [x, y] : list) {
            total -= (topics[x] - 1) * 1LL * (diffs[y] - 1);
        }
        cout << total << '\n';
    }
    return 0;
}