#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int fin;
vector<int> starts;
vector<vector<int>> Adj;
vector<vector<int>> dist;

void dfs(int i) {
    if (i == fin) return;
    
    for (int j = 0; j < n; j++) {
        int w = Adj[i][j];
        if (w != 0 && w < dist[i][j]) { // have edge from i to j
            dist[i][j] = w;
            dfs(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> m >> k;
    cin >> fin;
    
    Adj.assign(n, vector<int>(n, 0));
    dist.assign(n, vector<int>(n, 1e9));
    
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        starts.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        Adj[a][b] = w;
    }

    int minDist = 1e9;
    for (auto start_node : starts) {
        dfs(start_node);
        cout << "dist[start_node][fin]: "<<dist[start_node][fin];
        minDist = min(minDist, dist[start_node][fin]);
    }
    cout << minDist;

    return 0;
}