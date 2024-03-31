#include <iostream>

using namespace std;

int dist[105][105];

int main() {
    int n, e, s;
    cin >> n >> e >> s;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // detecting negative cycle
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "-1";
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) cout << dist[s][i] << ' ';

    return 0;
}