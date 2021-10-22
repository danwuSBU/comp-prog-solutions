import sys
def get_ints(): return map(float, sys.stdin.readline().strip().split())

n = list(get_ints())
expv = 0
for i in range(1, 7):
    expv += i * n[i - 1]
o = []
for i in range(1, 7):
    o.append(expv - i * n[i - 1])
expv = round(expv, 3)
if expv == 3.5:
    print('0.000')
    exit()
diff = float('inf')
for i in range(1, 7):
    if n[i - 1] == 0:
        continue
    x = (3.5 - o[i - 1]) / n[i - 1] - i
    if abs(x) < diff:
        diff = abs(x)
print(f"{diff:.3f}")
