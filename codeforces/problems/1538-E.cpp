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

struct stri {
    ll count;
    string pre;
    string suf;
};

void solve() {
    map<string, stri> d;
    auto strip = [] (string s) {
        string t;
        for EACH(x, s) {
            if (x != ' ') t.push_back(x);
        }
        return t;
    };
    auto ct = [] (string s) {
        int i = 0;
        int ret = 0;
        while (true) {
            int j = s.find("haha", i);
            if (j == string::npos) break;
            i = j + 1; ret++;
        }
        return ret;
    };
    int n; cin >> n; string last_assigned;
    getline(cin, last_assigned);
    REP(n) {
        string s; getline(cin, s);
        s = strip(s);
        if (count(s.begin(), s.end(), ':')) {
            int loc = s.find(':');
            last_assigned = s.substr(0, loc);
            string str = s.substr(loc + 2);
            stri t;
            t.count = ct(str);
            if (str.length() > 3) {
                t.pre = str.substr(0, 3);
                t.suf = str.substr(str.length() - 3, 3);
            }
            else {
                t.pre = str;
                t.suf = str;
            }
            d[last_assigned] = t;
        }
        else {
            int loc1 = s.find('='), loc2 = s.find('+');
            last_assigned = s.substr(0, loc1);
            stri a(d[s.substr(loc1 + 1, loc2 - loc1 - 1)]), b(d[s.substr(loc2 + 1)]);
            stri t;
            t.count = a.count + b.count;
            string str = a.suf + b.pre;
            t.count += ct(str);
            string s1 = a.pre + b.pre;
            if (s1.length() > 3) t.pre = s1.substr(0, 3);
            else t.pre = s1;
            string s2 = a.suf + b.suf;
            if (s2.length() > 3) t.suf = s2.substr(s2.length() - 3);
            else t.suf = s2;
            d[last_assigned] = t;
        }
    }
    cout << d[last_assigned].count << '\n';
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