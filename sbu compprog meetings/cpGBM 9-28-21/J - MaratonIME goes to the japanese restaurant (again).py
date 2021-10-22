import sys
import math
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, = get_ints()
circles = []
for _ in range(n):
    a, b, r = get_ints()
    circles.append((a, b, r))
for i in range(len(circles)):
    for j in range(i + 1, len(circles)):
        a, b, r1 = circles[i]
        c, d, r2 = circles[j]
        if r1 + r2 == math.sqrt((a - c) ** 2 + (b - d) ** 2):
            print(i + 1, j + 1)
