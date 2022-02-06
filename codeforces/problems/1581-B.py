import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, = get_ints()
output = []
for _ in range(n):
    a, b, c = get_ints()
    if c < 3:
        if a == 1 and b == 0 and c == 2:
            output.append('yes')
        else:
            output.append('no')
    elif c == 3:
        if a * (a - 1) // 2 == b:
            output.append('yes')
        else:
            output.append('no')
    else:
        if a - 1 <= b <= a * (a - 1) // 2:
            output.append('yes')
        else:
            output.append('no')
sys.stdout.write('\n'.join(output))
