#include <iostream>
#include <deque>
using namespace std;
typedef deque<int> dq;
// fast integer in

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t;
    string s = "";
    while (t--) {
        cin >> n;
        dq q;
        while (n--) {
            cin >> a;
            if (!q.size()) q.push_back(a);
            else {
                if (q[0] >= a) q.push_front(a);
                else q.push_back(a);
            }
        }
        for (auto i = q.begin(); i != q.end(); i++) s += to_string(*i) + " ";
        s += '\n';
    }
    cout << s;
    return 0;
}