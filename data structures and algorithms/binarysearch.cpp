// from https://codeforces.com/blog/entry/96699
// so i don't forget how to do binary search lmao
#include <bits/stdc++.h>

using namespace std;

template <typename T> int naive(vector<T> &a, T x) {
    int l = 0, r = (int) a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return (int) a.size();
}

// a is an array of the form [true, true, ..., false, false]
// we are trying to find what indexes true changes to false
template <typename T> int find_change(vector<T> &a, T x) {
    int l = -1, r = (int) b.size(); // [first, ..., l] is true, [r, ..., last] is false
    while (r - l > 1) { // while elements are not yet in either of the two sections
        int m = l + (r - l) / 2;
        if (a[m]) l = m;
        else r = m;
    }
    return l; // l is index of last true, r is index of first false
}