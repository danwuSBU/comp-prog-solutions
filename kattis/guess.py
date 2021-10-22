import sys
def get_string(): return sys.stdin.readline().strip()

low = 1
high = 1000
while low <= high:
    mid = (low + high) // 2
    sys.stdout.write(str(mid) + '\n')
    sys.stdout.flush()
    result = get_string()
    if result == 'correct':
        break
    if result == 'higher':
        low = mid + 1
    else:
        high = mid - 1