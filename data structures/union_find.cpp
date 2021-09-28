class union_find
{
    int* id, cnt, * sz;
public:
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

class UF:
    """An implementation of union find data structure.
    It uses weighted quick union by rank with path compression.
    """
    def __init__(self, N):
        self._id = list(range(N))
        self._count = N
        self._rank = [1] * N
    def find(self, p):
        """Find the set identifier for the item p."""
        id = self._id
        root = p
        while root != id[root]:
            root = id[root]
        while p != root:
            newp = id[p]
            id[p] = root
            p = newp
        return p
    def count(self):
        """Return the number of items."""
        return self._count
    def connected(self, p, q):
        """Check if the items p and q are on the same set or not."""
        return self.find(p) == self.find(q)
    def union(self, p, q):
        id = self._id
        rank = self._rank
        i = self.find(p)
        j = self.find(q)
        if i == j:
            return
        if rank[i] < rank[j]:
            id[i] = j
            rank[j] += rank[i]
        else:
            id[j] = i
            rank[i] += rank[j]
        self._count -= 1