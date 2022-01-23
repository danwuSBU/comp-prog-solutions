import sys
def get_str(): return sys.stdin.readline().strip()

n = int(sys.stdin.readline())
se = set()
lines = []
for _ in range(n):
    lines.append(get_str().split())
lines = sorted(lines, key= lambda x: -len(x))
while lines and len(lines[-1]) == 1:
    se.add(lines[-1][0])
    lines.pop()
for i in range(len(lines)):
    lines[i] = set([x for x in lines[i][1:-2]]), lines[i][-1]
changed = True
while changed and lines:
    changed = False
    newlines = []
    for s, t in lines:
        to_remove = []
        if 'and' in s:
            ok = True
            for x in s:
                if x not in se and x != 'and':
                    ok = False
                elif x != 'and':
                    to_remove.append(x)
        else:
            ok = False
            for x in s:
                if x in se and x != 'or':
                    ok = True
                elif x != 'or':
                    to_remove.append(x)
        for x in to_remove:
            s.remove(x)
        if ok:
            se.add(t)
            changed = True
        else:
            newlines.append((s, t))
    lines = newlines
print(len(se))