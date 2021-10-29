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