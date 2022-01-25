#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

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
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}

void solve() {
    int n; cin >> n;
    vector<p> A(n), B(n);
    FOR(i, 0, n) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    FOR(i, 0, n) {
        cin >> B[i].first;
        B[i].second = i + 1;
    }
    sort(A.begin(), A.end(), greater<p>());
    sort(B.begin(), B.end(), greater<p>());
    vector<vector<int>> graph(n + 1, vector<int>());
    FOR(i, 0, n - 1) {
        graph[A[i + 1].second].push_back(A[i].second);
        graph[B[i + 1].second].push_back(B[i].second);
    }
    vector<int> output(n, 0);
    set<int> visited;
    vector<int> stack{A[0].second, B[0].second};
    while (stack.size()) {
        int curr = stack.back();
        stack.pop_back();
        if (visited.count(curr)) continue;
        visited.insert(curr);
        output[curr - 1] = 1;
        for EACH(x, graph[curr]) {
            stack.push_back(x);
        }
    }
    output_vector(output, false);
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