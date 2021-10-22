from collections import deque
import sys
def get_strings(): return sys.stdin.readline().strip().split()

a, = get_strings()
output = []
front = deque()
back = deque()

def rebalance():
    if len(front) < len(back):
        front.append(back.popleft())
    elif len(back) + 1 < len(front):
        back.appendleft(front.pop())
for _ in range(int(a)):
    op, num = get_strings()
    if op == 'push_back':
        back.append(int(num))
    elif op == 'push_front':
        front.appendleft(int(num))
    elif op == 'push_middle':
        front.append(int(num))
    rebalance()
    if op == 'get':
        if int(num) < len(front):
            output.append(str(front[int(num)]))
        else:
            output.append(str(back[int(num) - len(front)]))
sys.stdout.write("\n".join(output))