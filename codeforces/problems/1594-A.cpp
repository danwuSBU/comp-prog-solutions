#include <iostream>
using namespace std;
int t;
long long n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cout << - (n - 1) << ' ' << n << '\n';
    }
    return 0;
}