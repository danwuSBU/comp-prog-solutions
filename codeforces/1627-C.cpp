#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive false

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    if (interactive) cout << endl;
    else cout << '\n';
}
template <typename T> T max(vector<T> V) {
    return *max_element(V.begin(), V.end());
}
template <typename T> T min(vector<T> V) {
    return *min_element(V.begin(), V.end());
}

void solve() {
    int n, u, v; cin >> n;
    vector<vector<int>> graph(n, vector<int>());
    map<p, int> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        m[p(min(u - 1, v - 1), max(u - 1, v - 1))] = i;
    }
    vector<p> stack;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() > 2) {
            cout << "-1\n";
            return;
        }
        if (graph[i].size() == 1) {
            stack = {p(i, 0)};
        }
    }
    vector<int> out(n - 1, 0);
    set<int> visited;
    while (stack.size()) {
        int index = stack.back().first;
        int num = stack.back().second;
        stack.pop_back();
        if (!visited.count(index)) {
            visited.insert(index);
            for (int &e : graph[index]) {
                int outindex = m[p(min(index, e), max(index, e))];
                if (!out[outindex]) {
                    out[outindex] = (num) ? 2 : 5;
                }
                stack.emplace_back(e, 1 - num);
            }
        }
    }
    output_vector(out);
}

int main() 
{
    speedup;
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}