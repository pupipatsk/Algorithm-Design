#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int dp[m+1];
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (i < coins[j]) continue;

            dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    
    cout << dp[m];
    
    // return 0;
}