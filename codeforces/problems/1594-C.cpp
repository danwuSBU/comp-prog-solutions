#include <iostream>
using namespace std;

int t, n;
char c;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> c;
        cin >> s;
        int index = -1;
        bool all = true;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c && index == -1) {
                index = i;
            }
            if (s[i] != c) {
                all = false;
            }
        }
        if (all) {
            cout << 0 << '\n';
            continue;
        }
        if (index >= (n / 2)) {
            cout << 1 << '\n' << index + 1 << '\n';
        }
        else {
            cout << 2 << '\n' << n - 1 << ' ' << n << '\n';
        }
    }
    return 0;
}