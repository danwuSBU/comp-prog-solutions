#define interactive 0

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
    int n; cin >> n;
    vector<string> words(n);
    for EACH(w, words) cin >> w;
    int maxnum = 0;
    for (char x : "abcde") {
        vector<int> neg, pos;
        for EACH(w, words) {
            int bal = 0;
            for EACH(c, w) {
                if (c == x) bal++;
                else bal--;
            }
            if (bal >= 0) pos.push_back(bal);
            else neg.push_back(bal);
        }
        int bruh = accumulate(pos.begin(), pos.end(), 0);
        if (bruh == 0) continue;
        sort(neg.begin(), neg.end(), greater<int>());
        int tot = neg.size();
        FOR(i, 0, neg.size()) {
            if (bruh + neg[i] > 0) {
                bruh += neg[i];
            }
            else {
                tot = i; break;
            }
        }
        maxnum = max(maxnum, tot + (int) pos.size());
    }
    cout << maxnum << '\n';
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