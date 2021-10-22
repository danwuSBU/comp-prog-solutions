import sys
def get_int(): return int(sys.stdin.readline().strip())

d = dict()
e = {'*': '*', '+': '+', '-': '-', '//': '/'}
for x in ['*', '+', '-', '//']:
    for y in ['*', '+', '-', '//']:
        for z in ['*', '+', '-', '//']:
            d[eval('4' + x + '4' + y + '4' + z + '4')] = '4 ' + e[x] + ' 4 ' + e[y] + ' 4 ' + e[z] + ' 4 = ' + str(eval('4' + x + '4' + y + '4' + z + '4'))
n = get_int()
output = []
for _ in range(n):
    a = get_int()
    if a in d:
        output.append(d[a])
    else:
        output.append('no solution')
sys.stdout.write('\n'.join(output))