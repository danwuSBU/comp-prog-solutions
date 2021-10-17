//unfinished
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long t, n, k, ret, x, y, z, N = 1000000007;
typedef pair<int, int> p;
typedef map<int, int> mp;
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
    if (exp % 2 == 0)
        return t;
    else
        return (base * t) % N;
}

mp predefined = mp();
set<int> marked;
int ret = 0;

void solve(long long dp[3], long long curr) {

}

int main() {
    cin >> k;
    cin >> n;
    while (n--) {
        cin >> t;
        cin >> s;
        if (s == "yellow" || s == "white") x = 0;
        if (s == "green" || s == "blue") x = 1;
        if (s == "red" || s == "orange") x = 2;
        predefined[t] = x;
        while (t > 0 && !marked.count(t)) {
            marked.insert(t);
            t /= 2;
        }
    }
    return 0;
}