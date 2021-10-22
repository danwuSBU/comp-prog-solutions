import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

def plates(a):
    s = 0
    for i in range(len(a)):
        s += a[i]
        if s > l:
            return i
    return len(a)

n, l = get_ints()
a = list(get_ints())
y = plates(a)
z = plates(a[::-1])
if y == z:
    print("Empate")
    exit()
if y > z:
    print("Yan")
else:
    print("Nathan")