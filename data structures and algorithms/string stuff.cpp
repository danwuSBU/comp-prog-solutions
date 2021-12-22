#include <bits/stdc++.h>
using namespace std;

string to_binary(int64_t n) {
    string str;
 
    while (n != 0) {
        str += char('0' + n % 2);
        n /= 2;
    }
 
    reverse(str.begin(), str.end());
    return str;
}