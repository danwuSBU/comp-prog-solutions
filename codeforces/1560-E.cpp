#define interactive 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V) {for (auto v : V) cout << v << ' '; if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

void solve() {
    string s, t; cin >> t;
    string order; set<char> found;
    for (int i = t.length() - 1; i >= 0; i--) {
        if (!found.count(t[i])) {
            found.insert(t[i]);
            order.push_back(t[i]);
        }
    }
    map<char, int> counter;
    for (char &c : t) {
        if (!counter.count(c)) counter[c] = 1;
        else counter[c]++;
    }
    for (int i = 0; i < order.size(); i++) {
        counter[order[i]] /= (order.size() - i);
    }
    for (int i = 0; i < t.length(); i++) {
        if (counter[t[i]]-- == 0) {
            s = t.substr(0, i);
            break;
        }
    }
    if (s == "") s = t;
    reverse(order.begin(), order.end());
    string ns(s), nt;
    for (char &c : order) {
        nt += ns;
        string nns;
        for (char &d : ns) {
            if (d != c) nns.push_back(d);
        }
        ns = nns;
    }
    if (nt == t) cout << s << ' ' << order << '\n';
    else cout << "-1\n";
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