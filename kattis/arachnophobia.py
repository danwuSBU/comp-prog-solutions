import sys, heapq as hq

def get_ints(): return map(int, sys.stdin.readline().strip().split())

def dijkstra(G, s):
    n = len(G)
    visited = [False]*n
    weights = [float('inf')]*n
    path = [None]*n
    queue = []
    weights[s] = 0
    hq.heappush(queue, (0, s))
    while len(queue) > 0:
        g, u = hq.heappop(queue)
        visited[u] = True
        for v, w in G[u]:
            if not visited[v]:
                f = g + w
                if f < weights[v]:
                    weights[v] = f
                    path[v] = u
                    hq.heappush(queue, (f, v))
    return weights

def dijkstra2(G, s, d, sds):
    n = len(G)
    visited = [False]*n
    weights = [float('inf')]*n
    path = [None]*n
    queue = []
    weights[s] = 0
    hq.heappush(queue, (0, s))
    while len(queue) > 0:
        g, u = hq.heappop(queue)
        visited[u] = True
        for v, w in G[u]:
            if sds[v] < d:
                continue
            if not visited[v]:
                f = g + w
                if f < weights[v]:
                    weights[v] = f
                    path[v] = u
                    hq.heappush(queue, (f, v))
    return weights

n, m, tt = get_ints()
adj_list = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, d = get_ints()
    adj_list[u].append((v, d))
    adj_list[v].append((u, d))
s, t = get_ints()
spiders = list(get_ints())[1:]
for x in spiders:
    adj_list[n].append((x, 0))
weights = dijkstra(adj_list, n)
maxw = low = 0
high = max(weights)
while low <= high:
    mid = (low + high) // 2
    dist = dijkstra2(adj_list, s, mid, weights)[t]
    if dist > tt:
        high = mid - 1
    else:
        maxw = max(maxw, mid)
        low = mid + 1
print(maxw)