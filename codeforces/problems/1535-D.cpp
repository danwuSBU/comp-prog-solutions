#define interactive 1

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = 1e9 + 7; //998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

void solve() {
    int k; cin >> k;
    string t; cin >> t;
    vector<char> s(t.size()); FOR(i, 0, t.size()) s[i] = t[i];
    vector<int> G(s.size(), 0);
    int n = pow(2, k - 1);
    FOR(i, 0, n) {
        if (s[i] == '?') G[i] = 2;
        else G[i] = 1;
    }
    int i = n;
    for (int j = 0; j < s.size() - 1; j += 2) {
        if (s[i] == '?') G[i] = G[j] + G[j + 1];
        else if (s[i] == '0') G[i] = G[j];
        else G[i] = G[j + 1];
        i++;
    }
    reverse(G.begin(), G.end());
    reverse(s.begin(), s.end());
    int q; cin >> q;
    while (q--) {
        int p; cin >> p;
        char c; cin >> c;
        p = pow(2, k) - p;
        s[p - 1] = c;
        while (p >= 1) {
            if (s[p - 1] == '?') {
                if (p * 2 < s.size()) G[p - 1] = G[p * 2] + G[p * 2 - 1];
                else G[p - 1] = 2;
            }
            else if (s[p - 1] == '0') {
                if (p * 2 < s.size()) G[p - 1] = G[p * 2];
                else G[p - 1] = 1;
            }
            else {
                if (p * 2 < s.size()) G[p - 1] = G[p * 2 - 1];
                else G[p - 1] = 1;
            }
            p /= 2;
        }
        cout << G[0] << '\n';
    }
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}