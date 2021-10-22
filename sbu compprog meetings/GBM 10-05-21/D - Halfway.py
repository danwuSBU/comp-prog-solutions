import sys

n = int(sys.stdin.readline())
total = (n - 1) * n // 2
midpoint = total // 2 + total % 2
x = 0
low = 1
high = n
while low <= high:
    mid = (low + high) // 2
    num = total - (n - mid) * (n - mid - 1) // 2
    prev = total - (n - mid) * (n - mid + 1) // 2
    if midpoint <= num:
        if prev < midpoint:
            print(mid)
            exit()
        else:
            high = mid - 1
    else:
        low = mid + 1
