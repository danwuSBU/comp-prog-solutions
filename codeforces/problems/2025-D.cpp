#define interactive 1

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define REP(a) FOR(_, 0, a)
#define EACH(a, x) (auto &a : x)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

ll mod = 1e9 + 7;
// 998244353;
int BIG32 = 1e9 + 5;

ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

template <typename T>
void output_vector(vector<T> &V, bool spaces = true)
{
    for (auto v : V)
    {
        if (spaces)
            cout << v << ' ';
        else
            cout << v;
    }
    if (interactive)
        cout << endl;
    else
        cout << '\n';
}
template <typename T>
T max(vector<T> &V) { return *max_element(V.begin(), V.end()); }
template <typename T>
T min(vector<T> &V) { return *min_element(V.begin(), V.end()); }
template <typename T>
T sum(vector<T> &V) { return accumulate(V.begin(), V.end(), T(0)); }
template <typename T>
T bisect_left(vector<T> &V, T x) { return lower_bound(V.begin(), V.end(), x) - V.begin(); } // must be sorted
template <typename T>
T bisect_right(vector<T> &V, T x) { return upper_bound(V.begin(), V.end(), x) - V.begin(); } // must be sorted

// preprocess //
void prepare()
{
}
// preprocess //
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for
        EACH(a, A)
        {
            cin >> a;
        }
    A.push_back(0); // to trigger line 101 one last time
    vector<int> DP(m + 1, 0);
    vector<int> D(m + 2, 0);

    int c = 0;
    for
        EACH(a, A)
        {
            if (a)
            {
                if (a > 0)
                {
                    if (c >= a)
                        D[a] += 1, D[c + 1] -= 1;
                }
                else
                {
                    if (c >= -a)
                        D[0] += 1, D[c + a + 1] -= 1;
                }
            }
            else
            {
                FOR(i, 0, m + 1)
                {
                    if (i > 0)
                        D[i] += D[i - 1];
                    DP[i] = max(DP[i], DP[i] + D[i]);
                }
                D = vector<int>(m + 2, 0);
                ROF(i, 1, m + 1)
                {
                    DP[i] = max(DP[i], DP[i - 1]);
                }
                c++;
            }
        }
    cout << max(DP) << '\n';
}

int main()
{
    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    prepare();
    if (interactive)
        solve();
    else
    {
        int t;
        cin >> t;
        REP(t)
        {
            solve();
        }
    }
    return 0;
}