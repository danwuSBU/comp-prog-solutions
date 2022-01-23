#define interactive 1

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REP(a) FOR(_,0,a)
#define EACH(a,x) (auto& a: x)

#define edge p
#define u first
#define v second

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

void solve() {
    int m, n, t; cin >> m >> n;
    vector<int> A(m);
    for EACH(a, A) cin >> a;
    vector<int> B(A);
    FOR(i, 1, m) {
        A[i] += A[i - 1];
    }
    ROF(i, 1, m) {
        B[i - 1] += B[i];
    }
    REP(n) {
        cin >> t;
        bool found = false;
        FOR(i, 0, m + 1) {
            int target = t, low, high, mid;
            if (i > 0) {
                target -= A[i - 1];
            }
            if (target == 0) {
                found = true;
                break;
            }
            low = i, high = m - 1;
            while (low <= high) {
                mid = (high - low) / 2 + low;
                if (B[mid] == target) {
                    found = true;
                    break;
                }
                if (B[mid] > target) low = mid + 1;
                else high = mid - 1;
            }
            if (found) {
                break;
            }
        }
        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
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