import sys
s = sys.stdin.readline().strip()
out = ''
count = 1
for x in range(1, len(s)):
    if s[x] == s[x - 1]:
        count += 1
    else:
        out += s[x - 1] + str(count)
        count = 1
out += s[-1] + str(count)
print(out)