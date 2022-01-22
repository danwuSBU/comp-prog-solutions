#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REP(a) F0R(_,a)
#define EACH(a,x) for (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

struct triple{
    int first, second, third;
    triple(int a, int b, int c) {
        first = a; second = b; third = c;
    }
};

bool operator <(const triple& x, const triple& y) {
    return std::tie(x.first, x.second, x.third) < std::tie(y.first, y.second, y.third);
}

void solve() {
    int n, m, r, c; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    FOR(j, 0, n) {
        string s; cin >> s;
        FOR(i, 0, m) {
            grid[j][i] = s[i];
            if (s[i] == 'L') {
                r = j; c = i;
            }
        }
    }
    vector<vector<int>> degrees(n, vector<int>(m));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int degree = 0;
            for (p par : {p(i - 1, j), p(i + 1, j), p(i, j - 1), p(i, j + 1)}) {
                int f = par.first, s = par.second;
                if (f >= 0 && f < n && s >= 0 && s < m && grid[f][s] == '.') degree++;
            }
            degrees[i][j] = degree;
        }
    }
    set<triple> visited;
    vector<triple> stack;
    for (p par : {p(r - 1, c), p(r + 1, c), p(r, c - 1), p(r, c + 1)}) {
        int f = par.first, s = par.second;
        if (f >= 0 && f < n && s >= 0 && s < m) {
            if (grid[f][s] == '.') stack.emplace_back(f, s, degrees[f][s]);
        }
    }
    while (stack.size()) {
        int i = stack.back().first, j = stack.back().second, k = stack.back().third;
        stack.pop_back();
        if (visited.count(triple(i, j, k))) continue;
        visited.insert(triple(i, j, k));
        bool next_win = false;
        for (p par : {p(i - 1, j), p(i + 1, j), p(i, j - 1), p(i, j + 1)}) {
            int f = par.first, s = par.second;
            if (f >= 0 && f < n && s >= 0 && s < m) {
                if (grid[f][s] == 'L' || grid[f][s] == '+') next_win = true;
            }
        }
        if (next_win && k <= 1) {
            grid[i][j] = '+';
            for (p par : {p(i - 1, j), p(i + 1, j), p(i, j - 1), p(i, j + 1)}) {
                int f = par.first, s = par.second;
                if (f >= 0 && f < n && s >= 0 && s < m && grid[f][s] == '.') {
                    degrees[f][s]--;
                    stack.emplace_back(f, s, degrees[f][s]);
                }
            }
        }
    }
    for (auto &row : grid) output_vector(row, false);
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}