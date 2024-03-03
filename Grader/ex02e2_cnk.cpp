#include <iostream>

using namespace std;

int table[50][50];

int binomial_naive(int n, int k) {
    if (n == k || k == 0) return 1;

    if (1 <= k <= n-1) {
        return binomial_naive(n-1, k-1) + binomial_naive(n-1, k);
    }
}

int binomial_TopDownDP(int n, int k) {
    if (n == k || k == 0) return 1;

    if (1 <= k <= n-1) {
        if (table[n][k] > 0) return table[n][k];

        int value = binomial_TopDownDP(n-1, k-1) + binomial_TopDownDP(n-1, k);
        table[n][k] = value;
        return value;
    }
}

int binomial_ButtomUpDP(int n, int k) {
    // Pascal Triangle
    for (int i = 0; i <= n; i++) {
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }
    return table[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << binomial_naive(n, k) <<"\n";
    cout << binomial_TopDownDP(n, k) <<"\n";
    cout << binomial_ButtomUpDP(n, k) <<"\n";
    
    return 0;
}