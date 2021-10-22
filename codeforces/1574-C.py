import sys
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, = get_ints()
l = sorted(list(get_ints()))
s = sum(l)
m, = get_ints()
output = []
for _ in range(m):
    df, at = get_ints()
    i = bisect.bisect_left(l, df)
    higher = l[i] if i < n else None
    lower = l[i - 1] if i > 0 else None
    if higher: sce1 = max(0, at - (s - higher))
    if lower: sce2 = df - lower + max(0, at - (s - lower))
    if higher and lower: output.append(str(min(sce1, sce2)))
    elif higher: output.append(str(sce1))
    else: output.append(str(sce2))
sys.stdout.write('\n'.join(output))