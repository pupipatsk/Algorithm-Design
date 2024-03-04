#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    int A[n][n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            A[i][j] = x;
            v.push_back(x);
        }
    }

    int B[n*n][n];
    int maxOfAll = -2e9; 
    for (int idx = 0; idx < n*n; idx++) {
        int maxInRow = -2e9;
        for (int lenToSum = 0; lenToSum < n; lenToSum++) {
            if (lenToSum == 0) {
                B[idx][0] = v[idx];
            }
            else {

                // idx = idxI*n + idxJ
                int idxI = idx / n;
                int idxJ = idx % n;

                B[idx][lenToSum] = A[idxI][idxJ];

                int round = lenToSum;
                while (round--)
                {
                    idxI++; idxJ++; 
                    if (idxI > n-1 || idxJ > n-1) break;
                    B[idx][lenToSum] += A[idxI][idxJ];
                }
            }
            
            if (B[idx][lenToSum] > maxInRow) maxInRow = B[idx][lenToSum];
        }
        if (maxInRow > maxOfAll) maxOfAll = maxInRow;
    }
    cout << maxOfAll;
    
    return 0;
}