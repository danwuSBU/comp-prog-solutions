import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

t, = get_ints()
for _ in range(t):
    n, d = get_ints()
    l = list(get_ints())
    visited = [0] * n
    maxlen = 0
    for i in range(n):
        currlen = 0
        while visited[i] == 0 and l[i] == 0:
            visited[i] = 1
            i = (i + d) % n
            if l[i] == 1:
                currlen += 1
                maxlen = max(maxlen, currlen)
            else:
                currlen = 0
            l[i] = 0
    if sum(l):
        maxlen = -1
    print(maxlen)
