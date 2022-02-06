import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

t, = get_ints()
output = []
for _ in range(t):
    n, x = get_ints()
    l = list(get_ints())
    m = sorted(l)
    flag = True
    for i in range(n - x, x):
        if l[i] != m[i]:
            flag = False
            break
    if flag:
        output.append('YES')
    else:
        output.append('NO')
sys.stdout.write("\n".join(output))
