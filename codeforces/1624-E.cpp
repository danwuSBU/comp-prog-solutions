#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7; 

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << endl;
}
template <typename T> T max(vector<T> V) {
    return *max_element(V.begin(), V.end());
}
template <typename T> T min(vector<T> V) {
    return *min_element(V.begin(), V.end());
}

void solve() {
    int n, m; string s; cin >> n >> m;
    map<string, vector<int>> numbs;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m - 1; j++) {
            string ss = s.substr(j, 2);
            if (!numbs.count(ss)) numbs[ss] = {j + 1, j + 2, i};
            if (j < m - 2) {
                ss = s.substr(j, 3);
                if (!numbs.count(ss)) numbs[ss] = {j + 1, j + 3, i};
            }
        }
    }
    cin >> s;
    vector<vector<int>> dp(m, vector<int>());
    if (m < 2) {
        cout << "-1\n";
        return;
    }
    map<int, int> path;
    if (numbs.count(s.substr(0, 2))) {
        dp[1] = numbs[s.substr(0, 2)];
        path[1] = -1;
    }
    if (m >= 3 && numbs.count(s.substr(0, 3))) {
        dp[2] = numbs[s.substr(0, 3)];
        path[2] = -1;
    }
    for (int i = 3; i < m; i++) {
        if (dp[i - 3].size()) {
            if (numbs.count(s.substr(i - 2, 3))) {
                dp[i] = numbs[s.substr(i - 2, 3)];
                path[i] = i - 3;
            }
        }
        if (dp[i - 2].size()) {
            if (numbs.count(s.substr(i - 1, 2))) {
                dp[i] = numbs[s.substr(i - 1, 2)];
                path[i] = i - 2;
            }
        }
    }
    if (dp.back().size()) {
        vector<vector<int>> output;
        int start = dp.size() - 1;
        while (start > 0) {
            output.push_back(dp[start]);
            start = path[start];
        }
        cout << output.size() << '\n';
        for (int i = output.size() - 1; i >= 0; i--) output_vector(output[i]);
    }
    else cout << "-1\n";
}

int main() 
{
    speedup;

    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}