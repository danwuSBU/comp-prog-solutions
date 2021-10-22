import sys
s = sys.stdin.readline().strip()
balance = 0
for x in s:
    if x == 'A':
        balance += 1
    else:
        balance -= 1
    if balance < 0:
        print("Nao")
        exit()
if balance == 0:
    print("Sim")
else:
    print("Nao")