#include <iostream>

using namespace std;

int main() {
    int n, m ,k;
    cin >> n >> m >> k;

    int A[n][m];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> A[row][col];
        }
    }
    
    int p[n][m];
    p[0][0] = A[0][0];
    for (int j = 1; j <= m-1; j++) {
        p[0][j] = p[0][j-1] + A[0][j];
    }
    for (int i = 1; i <= n-1; i++) {
        p[i][0] = p[i-1][0] + A[i][0];
        for (int j = 1; j <= m-1; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        if (r1 == 0 && c1 == 0) {
            cout << p[r2][c2] <<"\n";
        }
        else if (r1 == 0) {
            cout << p[r2][c2] - p[r2][c1-1] <<"\n";
        }
        else if (c1 == 0) {
            cout << p[r2][c2] - p[r1-1][c2] <<"\n";
        }
        else cout << p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1] <<"\n";
    }
    
    return 0;
}

// 3 5 7 
// 1 2 3 4 5
// 6 6 6 6 6
// 7 7 3 1 1
// 0 0 0 0
// 0 0 1 1
// 1 1 2 1
// 1 1 2 3
// 1 0 2 2
// 0 1 2 2
// 0 0 2 4