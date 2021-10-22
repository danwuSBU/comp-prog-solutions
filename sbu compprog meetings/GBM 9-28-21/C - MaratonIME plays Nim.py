import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
a, b = get_ints()
while True:
    if a > b:
        print(1, a - b)
        a = b
    else:
        print(2, b - a)
        b = a
    sys.stdout.flush()
    if a == 0 and b == 0:
        exit()
    x, y = get_ints()
    if x == 1:
        a -= y
    else:
        b -= y