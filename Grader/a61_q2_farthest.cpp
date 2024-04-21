#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // vector<vector<int>> Adj(n, vector<int>(n, 0));
    int Adj[n][n];
    // int dist[n]; // min distance from capital to each town
    vector<int> dist(n, 1e9);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Adj[i][j];
        }
    }

    // BFS
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        for (int j = 0; j < n; j++) {
            if (Adj[i][j] > 0) { // if have road from i to j
                // cout << "\ni: "<<i << " j: "<<j;
                int newDist = dist[i] + Adj[i][j];
                if (newDist < dist[j]) {
                    dist[j] = newDist;
                    q.push(j);
                }
            }
        }
    }
    
    // find max dist
    // cout << "\nDebug: ";
    int ans = -1;
    for (int i = 1; i < n; i++) {
        // cout << dist[i] << ' ';
        if (dist[i] == 1e9) {
            ans = -1;
            break;
        }
        ans = max(ans, dist[i]);
    }
    // cout << "\nans: " << ans;
    cout << ans;

    return 0;
}
