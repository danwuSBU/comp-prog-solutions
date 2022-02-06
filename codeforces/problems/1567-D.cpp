#include <bits/stdc++.h>
using namespace std;

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n; string s; cin >> t; while (t--) {
        vector<string> v;
        cin >> s >> n;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') {
                for (int j = 0; j < s[i] - '0'; j++) {
                    v.push_back('1' + string(s.length() - i - 1, '0'));
                }
            }
        }
        while (v.size() > n) {
            v.end()[-2] = to_string(stoi(v.end()[-2]) + stoi(v.back()));
            v.pop_back();
        }
        int ones = 0;
        while (v.size() + ones < n) {
            if (v.back().length() == 1) {
                ones += stoi(v.back());
                v.pop_back();
            }
            else {
                string x = v.back();
                if (x[0] == '1') {
                    v.pop_back();
                    v.push_back('1' + string(x.length() - 2, '0')); v.push_back('9' + string(x.length() - 2, '0'));
                }
                else {
                    v.pop_back();
                    v.push_back('1' + string(x.length() - 1, '0')); v.push_back((char) (x[0] - 1) + string(x.length() - 1, '0'));
                }
            }
        }
        if (v.size() + ones > n) {
            if (v.size() == 0) {
                v.push_back("0");
            }
            int diff = v.size() + ones - n;
            v.back() = to_string(stoi(v.back()) + diff);
            ones -= diff;
        }
        for (auto i = v.begin(); i != v.end(); i++) {
            cout << *i << ' ';
        }
        while (ones--) {
            cout << '1' << ' ';
        }
        cout << '\n';
    }
    return 0;
}