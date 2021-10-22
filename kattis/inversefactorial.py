import math, sys

def inf(k):
    n = int(k)
    if n <= 2: return n
    if n == 6: return 3
    if n == 24: return 4
    if n == 120: return 5
    if n == 720: return 6
    s = 0
    for i in range(2, 10 ** 6):
        s += math.log10(i)
        if math.ceil(s) == len(k):
            return i

sys.stdout.write(str(inf(sys.stdin.readline().strip())))