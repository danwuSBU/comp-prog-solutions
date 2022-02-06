#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef priority_queue<p, vector<p>, less<p>> pq;

int main() {
    int t, n, a, m;
    cin >> t;
    while (t--) {
        cin >> n;
        m = n;
        pq q;
        while (n--) {
            cin >> a;
            if (a) q.push(p(a, m - n));
        }
        string st = "";
        int u = 0;
        while (q.size() > 1) {
            u++;
            p f = q.top();
            q.pop();
            p s = q.top();
            q.pop();
            st += to_string(f.second) + ' ' + to_string(s.second) + '\n';
            if (f.first > 1) {
                q.push(p(f.first - 1, f.second));
            }
            if (s.first > 1) {
                q.push(p(s.first - 1, s.second));
            }
        }
        cout << u << '\n' << st;
    }
    return 0;
}