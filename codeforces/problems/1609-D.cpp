#define interactive 1

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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {if (n >= 0) init(n);} void init(int n) {data.assign(n + 1, -1); components = n;}
    
    int find(int x) {return data[x] < 0 ? x : data[x] = find(data[x]);}
    int get_size(int x) {return -data[find(x)];}
    bool unite(int x, int y) {x = find(x); y = find(y); if (x == y) return false; if (-data[x] < -data[y]) swap(x, y); data[x] += data[y]; data[y] = x; components--; return true;}
    bool connected(int x, int y) {return find(x) == find(y);}
};

void solve() {
    int n, d, x, y, size, moves; cin >> n >> d;
    union_find uf(n);
    for (int i = 1; i <= d; i++) {
        cin >> x >> y;
        uf.unite(x, y);
        vector<int> ufd(uf.data);
        sort(ufd.begin(), ufd.end());
        moves = i;
        for EACH(x, ufd) {
            if (x < 0) moves -= -x - 1;
        }
        size = -ufd[0];
        for (int j = 1; j <= moves; j++) {
            if (ufd[j] < 0) size += -ufd[j];
        }
        cout << size - 1 << '\n';
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