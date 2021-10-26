#include <bits/stdc++.h>
using namespace std;

int consider(string s, char c) {
    int del = 0, left = 0, right = s.length() - 1;
    while (left < right) {
        while (s[left] != s[right]) {
            if (s[left] == c) left++, del++;
            else if (s[right] == c) right--, del++;
            else return 100000;
        }
        left++, right--;
    }
    return del;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, ret;
    string s;
    cin >> t; while (t--) {
        cin >> n >> s;
        ret = 100000;
        for (char c : "abcdefghijklmnopqrstuvwxyz") {
            ret = min(ret, consider(s, c));
        }
        ret = (ret == 100000) ? -1 : ret;
        cout << ret << '\n';
    }
    return 0;
}