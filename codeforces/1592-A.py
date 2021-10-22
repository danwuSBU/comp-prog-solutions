import sys
import heapq
def get_ints(): return map(int, sys.stdin.readline().strip().split())

t, = get_ints()
output = []
for _ in range(t):
    n, h = get_ints()
    l = list(get_ints())
    heapq.heapify(l)
    x, y = heapq.nlargest(2, l)
    t = (h // (x + y)) * 2
    r = h % (x + y)
    if r == 0:
        output.append(str(t))
    elif r <= x:
        output.append(str(t + 1))
    else:
        output.append(str(t + 2))
sys.stdout.write("\n".join(output))
