#define interactive 1

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

void solve() {
    string s; cin >> s; vector<string> res;
    if (s.length() == 1) {
        if (s == "0" || s == "X" || s == "_") cout << "1\n";
        else cout << "0\n";
        return;
    }
    if (!count(s.begin(), s.end(), 'X')) {
        res = {s};
    }
    else {
        for (char c : {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}) {
            string newres;
            for EACH(a, s) {
                if (a == 'X') newres.push_back(c);
                else newres.push_back(a);
            }
            res.push_back(newres);
        }
    }
    int output = 0;
    for EACH(a, res) {
        if (a[0] == '0') continue;
        int c_ = count(a.begin(), a.end(), '_');
        int multiplier = 1;
        if (a[0] == '_') {
            multiplier = 9;
            c_--;
        }
        if (a.length() == 2) {
            if (a == "__") {
                output += 3;
                continue;
            }
            if (a[0] == '_') {
                if (a[1] == '0') {
                    output += 1;
                }
                if (a[1] == '5') {
                    output += 2;
                }
                continue;
            }
            if (a[1] == '_') {
                if (a[0] == '2' || a[0] == '7' || a[0] == '5') {
                    output += 1;
                }
                continue;
            }
            if (a == "25" || a == "50" || a == "75") {
                output += 1;
                continue;
            }
            continue;
        }
        if (a.length() > 2) {
            string lt = a.substr(a.length() - 2, 2);
            if (a.substr(a.length() - 2, 2) == "__") {
                multiplier *= 4;
                c_ -= 2;
            }
            else if (a.end()[-2] == '_') {
                if (a.end()[-1] == '0' || a.end()[-1] == '5') {
                    multiplier *= 2;
                    c_ -= 1;
                }
                else continue;
            }
            else if (a.end()[-1] == '_') {
                if (a.end()[-2] == '0' || a.end()[-2] == '2' || a.end()[-2] == '5' || a.end()[-2] == '7') {
                    c_ -= 1;
                }
                else continue;
            }
            else if (lt != "00" && lt != "25" && lt != "50" && lt != "75") continue;
        }
        output += pow(10, c_) * multiplier;
    }
    cout << output;
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