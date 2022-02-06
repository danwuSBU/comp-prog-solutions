#define interactive 1

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

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    union_find f1(n), f2(n);
    int u, v, out = 0; while(m1--) {
        cin >> u >> v;
        f1.unite(u, v);
    } while (m2--) {
        cin >> u >> v;
        f2.unite(u, v);
    }
    vector<p> pairs;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (f1.find(i) != f1.find(j) && f2.find(i) != f2.find(j)) {
                f1.unite(i, j);
                f2.unite(i, j);
                out++;
                pairs.emplace_back(i, j);
            }
        }
    }
    cout << out << '\n';
    for (p pair : pairs) {
        cout << pair.first << ' ' << pair.second << '\n';
    }
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