import sys
def get_string(): return sys.stdin.readline().strip()

t = int(sys.stdin.readline().strip())
for _ in range(t):
    out = []
    q = get_string().split()
    s = set()
    a = get_string()
    while a != "what does the fox say?":
        s.add(a.split()[2])
        a = get_string()
    for x in q:
        if x not in s:
            out.append(x)
    print(" ".join(out))