#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int A[n][n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < r+1; c++) {
            cin >> A[r][c];
        }
    }
    
    int S[n][n];
    S[0][0] = A[0][0];
    S[1][0] = A[1][0] + S[0][0];
    S[1][1] = A[1][1] + S[0][0];

    int ans = -2e9;
    if (n == 1) {
        ans = S[0][0];
    }
    else if (n == 2) {
        ans = max(S[1][0], S[1][1]);
    }
    else {
        for (int r = 2; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (c == 0) {
                    S[r][0] = S[r-1][0] + A[r][c];
                }
                else if (c == r) {
                    S[r][c] = S[r-1][c-1] + A[r][c];
                }
                else {
                    S[r][c] = max(S[r-1][c], S[r-1][c-1]) + A[r][c];
                }
                
                if (r == n-1) {
                    if (S[n-1][c] > ans) ans = S[n-1][c];
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}