#include <iostream>
#include <cmath>
using namespace std;
long long k, ret, N = 1000000007;
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
    ret = 6;
    k = exponentiation(2, k, INT64_MAX);
    ret = (ret * exponentiation(4, k, N)) % N;
    cout << ret;
}