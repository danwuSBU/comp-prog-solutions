import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
a, = get_ints()
x = list(get_ints())
y = max(x)
if x.count(y) > 1:
    print(-1)
else:
    print(x.index(y) + 1)