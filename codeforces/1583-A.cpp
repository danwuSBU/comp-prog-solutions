#include <bits/stdc++.h>
using namespace std;

bool composite(int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return true;
    }
    return false;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t; while (t--) {
        vector<int> v = vector<int>();
        bool allEven = true;
        int counter = 0, total = 0, odd = -1;
        cin >> n; while (n--) {
            cin >> a, total += a;
            if (a % 2 && allEven) allEven = false, odd = ++counter;
            else v.push_back(++counter);
        }
        cout << v.size() + (!allEven && composite(total)) << '\n';
        for (auto i = v.begin(); i != v.end(); i++) {
            cout << *i << ' ';
        }
        if (!allEven && composite(total)) cout << odd;
        cout << '\n';
    }
    return 0;
}