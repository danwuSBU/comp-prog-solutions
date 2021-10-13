#include <iostream>
using namespace std;

bool solve(int matrix[][5], int n) {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            bool works = true;
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) {
                left += matrix[k][i];
                right += matrix[k][j];
                if (!(matrix[k][i] || matrix[k][j])) {
                    works = false;
                    break;
                }
            }
            if (works && (left >= n / 2) && (right >= n / 2)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int matrix [n][5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> matrix[i][j];
            }
        }
        if (solve(matrix, n)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}