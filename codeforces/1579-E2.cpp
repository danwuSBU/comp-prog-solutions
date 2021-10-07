#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    string a = "";
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ordered_set s;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int less = s.order_of_key(node(a, 0)),
                    greater = i - s.order_of_key(node(a, n));
            cnt += min(less, greater);
            s.insert(node(a, i));
        }
        a += to_string(cnt) + "\n";
    }
    cout << a;
}