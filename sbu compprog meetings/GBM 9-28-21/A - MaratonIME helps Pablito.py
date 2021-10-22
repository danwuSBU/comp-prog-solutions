import math
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, = get_ints()
for _ in range(n):
    a, b = get_ints()
    if math.gcd(a, b) > 1:
        print("Sim")
    else:
        print("Nao")