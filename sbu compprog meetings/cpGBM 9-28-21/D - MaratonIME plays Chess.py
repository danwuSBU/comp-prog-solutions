import sys
def get_string(): return sys.stdin.readline().strip()

s = []
for _ in range(8):
    s.append(get_string())
d = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7}
p = get_string()
a = 8 - int(p[1])
b = d[p[0]]

def pawn(x, y):
    if x - 1 == a and (y - 1 == b or y + 1 == b):
        return True
    return False
def knight(x, y):
    if x - 2 == a and (y - 1 == b or y + 1 == b):
        return True
    if x + 2 == a and (y - 1 == b or y + 1 == b):
        return True
    if x - 1 == a and (y - 2 == b or y + 2 == b):
        return True
    if x + 1 == a and (y - 2 == b or y + 2 == b):
        return True
    return False
def bishop(x, y):
    for c in (1, -1):
        for d in (1, -1):
            e, f = x + c, y + d
            while 0 <= e < 8 and 0 <= f < 8:
                if a == e and b == f:
                    return True
                if s[e][f] != '.':
                    break
                e += c
                f += d
    return False
def rook(x, y):
    for c, d in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        e, f = x + c, y + d
        while 0 <= e < 8 and 0 <= f < 8:
            if a == e and b == f:
                return True
            if s[e][f] != '.':
                break
            e += c
            f += d
    return False
def queen(x, y):
    return rook(x, y) or bishop(x, y)
def king(x, y):
    for c, d in [(0, 1), (1, 0), (0, -1), (-1, 0), (1, -1), (1, 1), (-1, 1), (-1, -1)]:
        if x + c == a and y + d == b:
            return True
    return False
for i in range(len(s)):
    for j in range(len(s[0])):
        if s[i][j] == 'p':
            if pawn(i, j):
                print("Sim")
                exit()
        if s[i][j] == 'c':
            if knight(i, j):
                print("Sim")
                exit()
        if s[i][j] == 'b':
            if bishop(i, j):
                print("Sim")
                exit()
        if s[i][j] == 't':
            if rook(i, j):
                print("Sim")
                exit()
        if s[i][j] == 'r':
            if queen(i, j):
                print("Sim")
                exit()
        if s[i][j] == 'k':
            if king(i, j):
                print("Sim")
                exit()
print("Nao")