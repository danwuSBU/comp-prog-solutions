#include <iostream>
#include <vector>
using namespace std;

class union_find
{
     
public:
    int* id, cnt, * sz;
    // Create an empty union find data structure with N isolated sets.
    union_find(int N) {
        cnt = N; id = new int[N]; sz = new int[N];
        for (int i = 0; i < N; i++)  id[i] = i, sz[i] = 1;
    }
    ~union_find() { delete[] id; delete[] sz; }

    // Return the id of component corresponding to object p.
    int find(int p) {
        int root = p;
        while (root != id[root])    root = id[root];
        while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
        return root;
    }
    // Replace sets containing x and y with their union.
    void merge(int x, int y) {
        int i = find(x); int j = find(y); if (i == j) return;
        // make smaller root point to larger one
        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
        else { id[j] = i, sz[i] += sz[j]; }
        cnt--;
    }
    // Are objects x and y in the same set?
    bool connected(int x, int y) { return find(x) == find(y); }
    // Return the number of disjoint sets.
    int count() { return cnt; }
};

int main() {
    int n, m, a;
    cin >> n;
    cin >> m;
    union_find uf = union_find(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a;
        if (!(a & 0x00000008)) {
            uf.merge(i, i - m);
        }
        if (!(a & 0x00000004)) {
            uf.merge(i, i + 1);
        }
        if (!(a & 0x00000002)) {
            uf.merge(i, i + m);
        }
        if (!(a & 0x00000001)) {
            uf.merge(i, i - 1);
        }
    }
    vector<int> v = vector<int>(n * m + 1, 0);
    for (int i = 0; i < n * m; i++) {
        v[uf.sz[uf.find(i)]]++;
    }
    for (int i = n * m; i > 0; i--) {
        if (v[i]) {
            int times = v[i] / i;
            while (times--) {
                cout << i << ' ';
            }
        }
    }
    return 0;
}