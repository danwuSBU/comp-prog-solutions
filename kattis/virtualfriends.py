import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_strings(): return sys.stdin.readline().strip().split()

class UF:
    """An implementation of union find data structure.
    It uses weighted quick union by rank with path compression.
    """
    def __init__(self, N):
        self._id = list(range(N))
        self._count = N
        self._rank = [1] * N
        self.size = [1] * N
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

tc, = get_ints()
output = []
for _ in range(tc):
    f, = get_ints()
    net = UF(f * 2)
    d = dict()
    for _ in range(f):
        a, b = get_strings()
        if a not in d:
            d[a] = len(d)
        if b not in d:
            d[b] = len(d)
        net.union(d[a], d[b])
        output.append(net._rank[net.find(d[a])])
sys.stdout.write("\n".join(map(str, output)))