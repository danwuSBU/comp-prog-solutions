#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int, int> um;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    um odd = um(), even = um();
    cin >> t; while (t--) {
        cin >> n; for(int i = 0; i < n; i++) {
            cin >> a;
            odd[a] = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> a;
            even[a] = i;
        }
        int index = INT32_MAX, smallest = INT32_MAX;
        for (int i = 2 * n - 1; i > 0; i -= 2) {
            index = min(index, even[i + 1]);
            smallest = min(smallest, odd[i] + index);
        }
        cout << smallest << '\n';
    }
    return 0;
}