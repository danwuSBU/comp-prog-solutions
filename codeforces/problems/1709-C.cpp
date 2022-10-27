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

ll mod = /*1e9 + 7;*/ 998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    string S; cin >> S;
    int bal = 0, q = 0;
    for EACH(s, S) {
        if (s == '(') bal++;
        else if (s == ')') bal--;
        else q++;
    }
    if (q < bal || (bal + q) % 2) {
        cout << "NO\n";
        return;
    }
    if (!q) {
        cout << "YES\n";
        return;
    }
    int q1 = q - (bal + q) / 2, q0 = q1;
    string S0, S1;
    for EACH(s, S) {
        if (s == '?') {
            if (q0 > 0) S1.push_back('(');
            else S1.push_back(')');
            q0--;
        }
        else S1.push_back(s);
    }
    bal = 0;
    for EACH(s, S1) {
        if (s == '(') bal++;
        else bal--;
        if (bal < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (bal) {
        cout << "NO\n";
        return;
    }
    bal = 0;
    for EACH(s, S) {
        if (s == '?') {
            if (q1 == 1 || q1 < 0) S0.push_back(')');
            else if (q1 >= 0) S0.push_back('(');
            q1--;
        }
        else S0.push_back(s);
    }
    for EACH(s, S0) {
        if (s == '(') bal++;
        else bal--;
        if (bal < 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << ((bal) ? "YES\n" : "NO\n");
}

int main()
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    prepare();
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}