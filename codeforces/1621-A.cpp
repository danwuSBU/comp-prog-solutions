#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll inf32 = 1e18;
ll mod = 1e9 + 7; 

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    int n, k; cin >> n >> k;
    if ((n + 1) / 2 >= k) {
        vector<vector<char>> A(n, vector<char>(n, '.'));
        for (int i = 0; i < k; i++) {
            A[i * 2][i * 2] = 'R'; 
        }
        for (vector<char> a : A) {
            for (char c : a) cout << c;
            cout << '\n';
        }
    }
    else cout << "-1\n";
}

int main() 
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}