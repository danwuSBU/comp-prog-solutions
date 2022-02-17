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
template <typename T> T sum(vector<T> &V) {return accumulate(V.begin(), V.end(), 0);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}
template <typename T> T bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> T bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted


vector<int> primes;
vector<int> primelist(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> output;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        if (is_prime[i]) output.push_back(i);
    }
    return output;
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    auto moves = [] (int a) {
        int ret = 0;
        int limit = (int) sqrt(a) + 1;
        for EACH(p, primes) {
            if (p > limit || a == 1) break;
            while (a % p == 0) {
                a /= p;
                ret++;
            }
        }
        return ret + (a != 1);
    };
    if (k > 1) cout << ((moves(a) + moves(b) >= k) ? "YES\n" : "NO\n");
    else cout << (((a % b == 0 || b % a == 0) && a != b) ? "YES\n" : "NO\n");
}

int main() 
{
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);
    primes = primelist((int) sqrt(BIG32) + 1);
    if (interactive) solve();
    else {
        int t; cin >> t; REP(t) {
            solve();
        }
    }
    return 0;
}