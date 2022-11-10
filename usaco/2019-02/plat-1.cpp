#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
 
template <typename T> void output_vector(vector<T> V) {
    for (auto v : V) cout << v << ' ';
    cout << '\n';
}

void solve() {
    string line;
    ifstream MyReadFile("cowdate.in");
    getline(MyReadFile, line);
    int n = stoi(line);
    vector<double> P(n), Q(n); for (int i = 0; i < n; i++) {
        double &p = P[i], &q = Q[i];
        getline(MyReadFile, line);
        q = (double) stoi(line) / 1000000;
        p = q / (1 - q);
    }
    int runmax = 0, right = 0; double runsum = 0, runprod = 1;
    for (int left = 0; left < n; left++) {
        while (runsum < 1 && right < n) {
            runsum += P[right];
            runprod *= (1 - Q[right]);
            right++;
        }
        runmax = max(runmax, (int) (1000000 * runsum * runprod));
        runprod /= (1 - Q[left]);
        runsum -= P[left];
    }
    ofstream MyFile("cowdate.out");
    MyFile << runmax;
}

int main() 
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); return 0;
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}