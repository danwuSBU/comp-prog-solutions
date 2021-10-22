import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, q = get_ints()
b = list(get_ints())
output = []
for i in range(1, len(b)):
    b[i] += b[i - 1]
for _ in range(q):
    x, y = get_ints()
    if x == 1:
        s = b[y - 1]
    else:
        s = b[y - 1] - b[x - 2]
    if s % 2:
        output.append('Nao')
    else:
        output.append('Sim')
print("\n".join(output))