import sys
n = int(sys.stdin.readline().strip())
total = 0
while n != 0:
    n = n // 2
    total += 1
print(total)