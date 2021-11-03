//  unfinished
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a; vector<int> v;
    cin >> t; while(t--) {
        cin >> n; while (n--) {
            cin >> a; v.push_back(a);
        }
        int m = 2 * (*max_element(v.begin(), v.end()));
        
    }
    return 0;
}