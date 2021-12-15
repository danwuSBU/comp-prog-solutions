#include <bits/stdc++.h>
using namespace std;

vector<bool> primes(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }   
    return is_prime;
}

vector<bool> p = primes(1000000);

void solve() {
    int n, e; cin >> n >> e;
    vector<int> v(n); long long total = 0;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < e; i++) {
        vector<int> group(1, 1);
        for (int j = i; j < n; j += e) {
            if (v[j] == 1) group.back()++;
            else if (!p[v[j]]) {
                if (group.size() > 1) {
                    for (int k = 0; k < group.size() - 1; k++) {
                        total += (long long) group[k] * group[k + 1] - 1;
                    }
                }
                group = vector<int>(1, 1);
            }
            else {
                group.push_back(1);
            }
        }
        if (group.size() > 1) {
            for (int k = 0; k < group.size() - 1; k++) {
                total += (long long) group[k] * group[k + 1] - 1;
            }
        }
        group = vector<int>(1, 1);
    }
    cout << total << '\n';
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}