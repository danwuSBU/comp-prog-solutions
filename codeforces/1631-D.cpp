#define interactive 0

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

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
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();}
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n); for EACH(a, A) cin >> a;
    vector<int> orA = A;
    sort(A.begin(), A.end());
    int x = *min_element(A.begin(), A.end()), y = *max_element(A.begin(), A.end()), maxx = y, smallest = y - x;
    FOR(i, x, maxx + 1) {
        int low = i, high = maxx, mid, rank = bisect_left(A, i);
        while (low < high) {
            mid = (high - low) / 2 + low;
            if (2 * (bisect_right(A, mid) - rank) - n >= k) high = mid;
            else low = mid + 1;
        }
        if (2 * (bisect_right(A, low) - rank) - n >= k && low - i < smallest) {
            smallest = low - i;
            x = i;
            y = low;
        }
    }
    int prefix = 0;
    cout << x << " " << y << '\n';
    int curr = 0, found = 0;
    FOR(i, 0, n) {
        if (orA[i] >= x && orA[i] <= y) prefix++;
        else prefix--;
        if (prefix > 0 && found < k - 1) {
            found++;
            prefix = 0;
            cout << curr + 1 << ' ' << i + 1 << '\n';
            curr = i + 1;
        }
    }
    cout << curr + 1 << ' ' << n << '\n';
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