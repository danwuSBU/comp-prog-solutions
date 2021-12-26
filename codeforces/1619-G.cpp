#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {if (n >= 0) init(n);} void init(int n) {data.assign(n + 1, -1); components = n;}
    
    int find(int x) {return data[x] < 0 ? x : data[x] = find(data[x]);}
    int get_size(int x) {return -data[find(x)];}
    bool unite(int x, int y) {x = find(x); y = find(y); if (x == y) return false; if (-data[x] < -data[y]) swap(x, y); data[x] += data[y]; data[y] = x; components--; return true;}
};

struct mine {
    int x; int y; int time; int index;
};

void solve() {
    int n, k; cin >> n >> k;
    vector<mine> A(n);
    auto uf = union_find(n);
    for (int i = 0; i < n; i++) {
        mine &a = A[i];
        cin >> a.x >> a.y >> a.time;
        a.index = i;
    }
    sort(A.begin(), A.end(), [](mine a, mine b) {if (a.x != b.x) return a.x < b.x; else return a.y < b.y;});
    for (int i = 0; i < n - 1; i++) {
        if (A[i].x == A[i + 1].x) {
            if (abs(A[i].y - A[i + 1].y) <= k) uf.unite(A[i].index, A[i + 1].index);
        }
    }
    sort(A.begin(), A.end(), [](mine a, mine b) {if (a.y != b.y) return a.y < b.y; else return a.x < b.x;});
    for (int i = 0; i < n - 1; i++) {
        if (A[i].y == A[i + 1].y) {
            if (abs(A[i].x - A[i + 1].x) <= k) uf.unite(A[i].index, A[i + 1].index);
        }
    }
    sort(A.begin(), A.end(), [](mine a, mine b) {return a.time < b.time;});
    unordered_map<int, int> times;
    for (mine a : A) {
        int component_head = uf.find(a.index);
        if (!times.count(component_head)) times[component_head] = a.time;
    }
    vector<int> t;
    for (auto const &[key, value] : times) {
        t.push_back(value);
    }
    sort(t.begin(), t.end());
    int left = 0, right = t.size() - 1;
    for (int time = 0; time < 1e9 + 1; time++) {
        while (t[left] == time) left++;
        right--;
        if (left > right) {
            cout << time << '\n';
            return;
        }
    }
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