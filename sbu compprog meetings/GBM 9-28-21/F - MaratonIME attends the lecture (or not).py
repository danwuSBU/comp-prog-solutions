import sys
import math
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, m, k = get_ints()
need = max(math.ceil(0.7 * n - k), 0)
if n - m < need:
    print(-1)
elif n == k:
    print(0)
else:
    print(need)
print(int((k + n - m) / n * 100))
