import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_string(): return sys.stdin.readline().strip()

x, y = get_ints()
maxc = 0
c = 0
for i in range(x):
    s = get_string()
    if i % 2 == 1:
        s = s[::-1]
    for j in s:
        if j == '.':
            c += 1
            maxc = max(maxc, c)
        if j == 'L':
            c = 0
print(maxc)
