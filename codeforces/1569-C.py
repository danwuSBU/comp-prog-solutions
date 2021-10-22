import sys
import heapq
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def factorial(n, k):
    out = 1
    for i in range(2, n + 1):
        if i != k:
            out = out * i % 998244353
    return out
t, = get_ints()
output = []
for _ in range(t):
    n, = get_ints()
    l = list(get_ints())
    heapq.heapify(l)
    x, y = heapq.nlargest(2, l)
    k = l.count(y)
    if x == y:
        output.append(str(factorial(n,0)))
    elif y == x - 1:
        output.append(str((factorial(n,0) - factorial(n,k+1)) % 998244353))
    else:
        output.append('0')
sys.stdout.write('\n'.join(output))