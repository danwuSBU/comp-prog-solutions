#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;
vector<ll> bmask;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> &V, bool spaces=true) {for (auto v : V) {if (spaces) cout << v << ' '; else cout << v;} if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> &V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> &V) {return *min_element(V.begin(), V.end());}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

void solve() {
    int x, a, b; cin >> x >> a >> b;
    if (x == 1 && a == 1 && b == 1) {
        cout << "1\n";
        return;
    }
    if (x != a) {
        if (x % a == 0) {
            b *= x / a;
            a *= x / a;
        }
    }
    if (x == a && b != 1) {
        vector<int> divisors = {1, b}; int c = (int) sqrt(b) + 1;
        if ((int) sqrt(b) == sqrt(b)) {
            divisors.push_back((int) sqrt(b)); c = (int) sqrt(b);
        }
        FOR(i, 2, c) {
            if (b % i == 0) {
                divisors.push_back(i);
                divisors.push_back(b / i);
            }
        }
        if (accumulate(divisors.begin(), divisors.end(), 0) == x) cout << b << '\n';
        else cout << "-1\n";
        return;
    }
    cout << "-1\n";
}

int main() 
{
    bmask.push_back(1);
    REP(62) bmask.push_back(bmask.back() * 2);
    reverse(bmask.begin(), bmask.end());
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (interactive) solve();
    else {
        int t; cin >> t; while (t--) {
            solve();
        }
    }
    return 0;
}