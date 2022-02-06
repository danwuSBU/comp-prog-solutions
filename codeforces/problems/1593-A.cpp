#include <iostream>
using namespace std;

int main() {
    int a, b, c, t;
    cin >> t;
    while (t--) {
        cin >> a;
        cin >> b;
        cin >> c;
        int m = max(max(a, b), c);
        int s = 0;
        for (int x : {a, b, c}) {
            if (x == m) {
                s++;
            }
        }
        if (s > 1) {
            cout << m + 1 - a << ' ' << m + 1 - b << ' ' << m + 1 - c << ' ';
        }
        else {
            for (int x : {a, b, c}) {
                if (x == m) {
                    cout << 0 << ' ';
                }
                else {
                    cout << m + 1 - x << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}