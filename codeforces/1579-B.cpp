#define interactive 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll mod = 1e9 + 7;
int BIG32 = 1e9 + 5;

ll powmod(ll a,ll b) {ll res = 1; a %= mod; assert(b >= 0); for(; b; b >>= 1){if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

template <typename T> void output_vector(vector<T> V) {for (auto v : V) cout << v << ' '; if (interactive) cout << endl; else cout << '\n';}
template <typename T> T max(vector<T> V) {return *max_element(V.begin(), V.end());}
template <typename T> T min(vector<T> V) {return *min_element(V.begin(), V.end());}

void solve() {
    int n; cin >> n;
    vector<p> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end(), greater<p>());
    int shifts = 0;
    vector<string> output;
    for (int i = 0; i < A.size(); i++) {
        if (A[i].second + 1 != n) {
            output.push_back("1 " + to_string(n) + " " + to_string(A[i].second + 1) + "\n");
            for (int j = i + 1; j < A.size(); j++) {
                A[j].second -= (A[i].second + 1);
                if (A[j].second < 0) A[j].second += n;
            }
        }
        n--;
    }
    cout << output.size() << '\n';
    for (string &s : output) cout << s;
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