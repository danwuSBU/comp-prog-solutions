#define interactive 1

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_, 0, a)
#define EACH(a, x) (auto &a: x)

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
template <typename T> int bisect_left(vector<T> &V, T x) {return lower_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted
template <typename T> int bisect_right(vector<T> &V, T x) {return upper_bound(V.begin(), V.end(), x) - V.begin();} // must be sorted

// preprocess //
void prepare() {

}
// preprocess //

void solve() {
    auto ask1 = [] (int a) {
        cout << "? 1 " << a << endl;
        string x; cin >> x;
        return x;
    };
    auto ask2 = [] (int a, int b) {
        cout << "? 2 " << a << ' ' << b << endl;
        int x; cin >> x;
        if (x == 0) exit(EXIT_FAILURE);
        return x;
    };
    auto fu = [] (string &s, int st) {
        set<char> sc;
        FOR(i, st, s.size()) sc.insert(s[i]);
        return sc.size();
    };
    int n; cin >> n;
    int u = 0;
    string s;
    map<char, int> M;
    FOR(i, 0, n) {
        int r = ask2(1, i + 1);
        if (r > u) {
            u = r;
            string x = ask1(i + 1);
            s += x;
        }
        else {
            vector<int> V;
            for EACH(m, M) {
                V.push_back(m.second);
            }
            sort(V.begin(), V.end());
            int l = 0, h = V.size();
            while (h > l + 1) {
                int mid = (h + l) / 2;
                if (fu(s, V[mid]) == ask2(V[mid] + 1, i + 1)) l = mid;
                else h = mid;
            }
            s += s[V[l]];
        }
        M[s.back()] = i;
    }
    cout << "! " << s << endl;
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