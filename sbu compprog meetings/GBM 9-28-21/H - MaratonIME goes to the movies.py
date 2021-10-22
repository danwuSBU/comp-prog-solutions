import sys
import math
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def ed(first, second):
    s = 0
    for i in range(len(first)):
        s += (first[i] - second[i]) ** 2
    return math.sqrt(s)
n, = get_ints()
floor = list(get_ints())
foot = list(get_ints())
chain = list(get_ints())
if ed(floor, foot) <= ed(floor, chain):
    print("Yan")
else:
    print("MaratonIME")