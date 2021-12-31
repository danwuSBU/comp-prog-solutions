#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, double> pd;
const ll mod=1000000007;

struct student {
    int m; int k;
};

void solve() {
    int n; cin >> n;
    vector<student> A(n);
    for (student &a : A) cin >> a.m >> a.k;
    double running = 0;
    vector<pd> best;
    for (int t = 1; t <= 20; t++) {
        unordered_map<int, double> messages;
        for (student a : A) {
            if (a.k >= t) {
                if (messages.count(a.m)) messages[a.m]++;
                else messages[a.m] = 1;
            }
            else {
                if (messages.count(a.m)) messages[a.m] += (double) a.k / t;
                else messages[a.m] = (double) a.k / t;
            }
        }
        vector<pd> msgs;
        for (const auto &[key, value] : messages) msgs.emplace_back(key, value);
        sort(msgs.begin(), msgs.end(), [](pd a, pd b) {return a.second > b.second;});
        double total = 0;
        for (int i = 0; i < min(t, (int) msgs.size()); i++) total += msgs[i].second;
        if (total > running) {
            running = total;
            best.resize(t);
            best = vector<pd>(msgs.begin(), msgs.begin() + t);
        }
    }
    cout << best.size() << '\n';
    for (pd m : best) cout << m.first << ' ';
}

int main() 
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}