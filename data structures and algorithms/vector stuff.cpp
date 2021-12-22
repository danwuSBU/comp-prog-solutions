#include <bits/stdc++.h>
using namespace std;

long long bisect_left(vector<long long> v, long long x) {
    long long low = 0, high = v.size() - 1, mid;
    if (x > v.back()) return v.size();
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (v[mid] >= x && (mid == 0 || v[mid - 1] < x)) return mid;
        if (v[mid] >= x) high = mid - 1;
        else low = mid + 1;
    }
}

long long bisect_right(vector<long long> v, long long x) {
    long long low = 0, high = v.size() - 1, mid;
    if (x > v.back()) return v.size();
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (v[mid] > x && (mid == 0 || v[mid - 1] <= x)) return mid;
        if (v[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
}

vector<int> prefix_sum(vector<int> v) {
    for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    return v;
}