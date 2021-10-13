#include <iostream>
using namespace std;

int main() {
    int t, n;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a;
        cin >> b;
        bool ret = true;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '1' && b[i] == '1') {
                ret = false;
                break;
            }
        }
        if (ret) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}