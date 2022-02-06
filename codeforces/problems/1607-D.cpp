#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a; string values;
    cin >> t; while (t--) {
        cin >> n; vector<int> b, r, numbers; for (int i = 0; i < n; i++) {
            cin >> a; numbers.push_back(a);
        }
        cin >> values;
        for (int i = 0; i < values.length(); i++) {
            if (values[i] == 'B') b.push_back(numbers[i]);
            else r.push_back(numbers[i]);
        }
        sort(b.begin(), b.end());
        sort(r.begin(), r.end(), greater<int>()); string ok = "YES";
        for (int i = 0; i < b.size(); i++) {
            if (b[i] < i + 1) ok = "NO";
        }
        for (int i = 0; i < r.size(); i++) {
            if (r[i] > n - i) ok = "NO";
        }
        cout << ok << '\n';
    }
    return 0;
}