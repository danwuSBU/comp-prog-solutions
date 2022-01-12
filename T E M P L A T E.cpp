#include <bits/stdc++.h>

#define speedup cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define interactive false

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

vector<int> bitmask(1);
 
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

// from neal
struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {if (n >= 0) init(n);} void init(int n) {data.assign(n + 1, -1); components = n;}
    
    int find(int x) {return data[x] < 0 ? x : data[x] = find(data[x]);}
    int get_size(int x) {return -data[find(x)];}
    bool unite(int x, int y) {x = find(x); y = find(y); if (x == y) return false; if (-data[x] < -data[y]) swap(x, y); data[x] += data[y]; data[y] = x; components--; return true;}
};

struct edge {
    int u, v, w;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    int OR = 0;
    for (edge &e : edges) {
        cin >> e.u >> e.v >> e.w;
        OR |= e.w;
    }
    for (int b : bitmask) {
        if (OR & b) {
            int newOR = OR - b;
            union_find dsu(n);
            for (edge &e : edges) {
                if ((newOR | e.w) == newOR) dsu.unite(e.u, e.v);
            }
            if (dsu.components == 1) OR = newOR;
        }
    }
    cout << OR << '\n';
}

int main() 
{
    bitmask[0] = 1;
    for (int i = 0; i < 30; i++) {
        bitmask.push_back(bitmask.back() << 1);
    }
    reverse(bitmask.begin(), bitmask.end());
    speedup;
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}