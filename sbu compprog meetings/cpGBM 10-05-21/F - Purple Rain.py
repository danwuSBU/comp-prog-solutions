import sys

s = sys.stdin.readline().strip()
balance = 0
minb = float('inf')
maxb = -1
minbi = maxbi = -1
maxr = 0
maxi = -1, -1
for i, x in enumerate(s):
    if x == 'B':
        balance += 1
    else:
        balance -= 1
    if balance < minb:
        minb = balance
        minbi = i
    if balance > maxb:
        maxb = balance
        maxbi = i
    if abs(balance) > maxr:
        maxr = abs(balance)
        maxi = -1, i
    if abs(balance - minb) > maxr:
        maxr = abs(balance - minb)
        maxi = minbi, i
    if abs(balance - maxb) > maxr:
        maxr = abs(balance - maxb)
        maxi = maxbi, i
print(maxi[0] + 2, maxi[1] + 1)
