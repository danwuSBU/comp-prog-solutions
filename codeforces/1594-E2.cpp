//unfinished
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
long long t, n, k, ret, x, y, z, N = 1000000007;
typedef pair<int, int> p;
typedef vector<p> vp;
string s;
long long exponentiation(long long base,
                        long long exp, long long N)
{
    if (exp == 0)
        return 1;
  
    if (exp == 1)
        return base % N;
  
    long long t = exponentiation(base, exp / 2, N);
    t = (t * t) % N;
  
    // if exponent is even value
    if (exp % 2 == 0)
        return t;
  
    // if exponent is odd value
    else
        return (base * t) % N;
}

int main() {
    cin >> k;
    cin >> n;
    int m = n;
    vp pairs = vp();
    x = 0;
    z = 0;
    ret = 6;
    set<int> st;
    while (n--) {
        cin >> t;
        cin >> s;
        if (s == "yellow" || s == "white") x = 0;
        if (s == "green" || s == "blue") x = 1;
        if (s == "red" || s == "orange") x = 2;
        pairs.push_back(p(t, x));
        st.insert(t);
        if (t == 1) {
            ret = 4;
        }
        if (ret == 6 & (t == 2 || t == 3)) {
            ret = 4;
        }
    }
    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i + 1; j < pairs.size(); j++) {
            int f = min(pairs[i].first, pairs[j].first);
            int s = max(pairs[i].first, pairs[j].first);
            if (s == f * 2 || s == f * 2 + 1) {
                if (pairs[i].second == pairs[j].second) {
                    cout << 0;
                    return 0;
                }
            }
            if (s == f * 4 || s == f * 4 + 1 || s == (f * 2 + 1) * 2 || s == (f * 2 + 1) * 2 + 1) {
                if (!st.count(f / 2) && pairs[i].second != pairs[j].second) {
                    z += 1;
                    st.insert(f / 2);
                }
            }
        }
    }
    k = exponentiation(2, k, INT64_MAX) - 2 - m;
    k = k - (z / 2 + z % 2);
    if (k < 0) {
        cout << 1;
        return 0;
    }
    ret = (ret * exponentiation(4, k, N)) % N;
    if (z % 2) ret = (ret * 2) % N;
    cout << ret;
    return 0;
}