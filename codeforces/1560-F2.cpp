#define interactive 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

void solve() {
    string n; int k; cin >> n >> k;
    vector<int> num;
    for (char &c : n) num.push_back(c - '0');
    int p = 0;
    while (p != n.length()) {
        set<int> used;
        p = n.length();
        for (int i = 0; i < n.length(); i++) {
            if (!used.count(num[i])) used.insert(num[i]);
            if (used.size() > k) {
                p = i;
                break;
            }
        }
        if (p != n.length()) {
            int a = 0;
            for (int i = 0; i <= p; i++) a = a * 10 + num[i];
            a++;
            for (int i = p; i >= 0; i--) {
                num[i] = a % 10;
                a /= 10;
            }
            for (int i = p + 1; i < n.length(); i++) num[i] = 0;
        }
    }
    output_vector(num, false);
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}