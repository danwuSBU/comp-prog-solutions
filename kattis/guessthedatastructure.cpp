//https://open.kattis.com/problems/guessthedatastructure
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;

// fast integer in
void fastscan(int& ret) {
    ret = 0;
    char r;
    bool start = false, neg = false;
    while (true) {
        r = getchar();
        if (r == EOF) {
            ret = -1;
            return;
        }
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
            continue;
        }
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
            break;
        }
        if (start)ret *= 10;
        start = true;
        if (r == '-')neg = true;
        else ret += r - '0';
    }
    if (neg) ret *= -1;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    bool x, y, z;
    priority_queue<int> pq;
    stack<int> s;
    queue<int> q;
    while (true) {
        fastscan(n);
        if (n < 0) return 0;
        pq = priority_queue<int>();
        s = stack<int>();
        q = queue<int>();
        x = true, y = true, z = true;
        for (int i = 0; i < n; i++) {
            fastscan(a);
            fastscan(b);
            if (a == 1) {
                if (x) s.push(b);
                if (y) q.push(b);
                if (z) pq.push(b);
            }
            else {
                if (x) {
                    if (s.empty()) {
                        x = false;
                    }
                    else {
                        if (b != s.top()) {
                            x = false;
                        }
                        else {
                            s.pop();
                        }
                    }
                }
                if (y) {
                    if (q.empty()) {
                        y = false;
                    }
                    else {
                        if (b != q.front()) {
                            y = false;
                        }
                        else {
                            q.pop();
                        }
                    }
                }
                if (z) {
                    if (pq.empty()) {
                        z = false;
                    }
                    else {
                        if (b != pq.top()) {
                            z = false;
                        }
                        else {
                            pq.pop();
                        }
                    }
                }
            }
        }
        if (x + y + z > 1) {
            cout << "not sure" << '\n';
        }
        else if (x + y + z == 0) {
            cout << "impossible" << '\n';
        }
        else {
            if (x) cout << "stack" << '\n';
            if (y) cout << "queue" << '\n';
            if (z) cout << "priority queue" << '\n';
        }
    }
    return 0;
}