#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int t, a, b, remove;
    cin >> t;
    while (t--) {
        cin >> s;
        reverse(s.begin(), s.end());
        a = s.find("0");
        remove = INT32_MAX;
        if (a != string::npos && a != s.length() - 1) {
            b = min(s.find("5", a + 1), s.find("0", a + 1));
            if (b != string::npos) remove = b - 1;
        }
        a = s.find("5");
        if (a != string::npos && a != s.length() - 1) {
            b = min(s.find("2", a + 1), s.find("7", a + 1));
            if (b != string::npos) remove = min(remove, b - 1);
        }
        cout << remove << '\n';
    }
}