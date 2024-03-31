#include <iostream>
#include <vector>

using namespace std;

int dist[105];

int main() {
    int n, e, s;
    cin >> n >> e >> s;

    vector<pair<pair<int, int>, int>> edgelist; // { {{a,b}, w}, ... }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back({{a, b}, c});
    }

    for (int i = 0; i < n; i++) dist[i] = 1e9;

    dist[s] = 0;
    for (int i = 1; i <= n-1; i++) { // shortest path can have at most n - 1 edges
        for (auto &e : edgelist) {
            int a = e.first.first;
            int b = e.first.second;
            int w = e.second;

            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    
    // detecting negative cycle
    for (auto &e : edgelist) {
        int a = e.first.first;
        int b = e.first.second;
        int w = e.second;
        
        if(dist[b] > dist[a] + w) {
            cout << "-1";
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) cout << dist[i] << ' ';

    return 0;
}