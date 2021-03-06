#include <bits/stdc++.h>
using namespace std;

// call like this:
// vector<bool> p = primes(int n);
// p[x] is true iff x <= n and x is prime
vector<bool> primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

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