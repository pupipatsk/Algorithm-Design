#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1005;
vector<int> adj[MAX_N];
int dist[MAX_N];

int main() {
    int n, e, k;
    cin >> n >> e >> k;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) dist[j] = -1;

        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] == k) break;

            for (auto &v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    cnt++;
                    q.push(v);                    
                }
            }
        }
        
        ans = max(ans, cnt);
    }
    
    cout << ans;

    return 0;
}