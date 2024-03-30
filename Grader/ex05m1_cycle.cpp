#include <iostream>
#include <vector>

using namespace std;

bool visited[1005];
vector<int> AdjList[1005]; // List of all neighbor

bool dfs_cd(int u, int parent) {
    if (visited[u] == true) return true; // cycle detected
    
    visited[u] = true;
    for (auto &v : AdjList[u]) {
        if (v == parent) continue;

        if(dfs_cd(v, u) == true) return true; // cycle detected
    }

    return false; // no cycle detected
}

int main() {
    int T; 
    cin >> T;

    while (T--)
    {
        int N, E; 
        cin >> N >> E;

        for(int i = 0; i < N; i++) {
            visited[i] = false;
            AdjList[i].clear();
        }
        
        while (E--)
        {
            int v1, v2; 
            cin >> v1 >> v2;
            
            AdjList[v1].push_back(v2);
            AdjList[v2].push_back(v1);
        }

        bool cycle_detected = false;
        for (int i = 0; i < N; i++) {
            if (visited[i] == false) {
                if (dfs_cd(i, -1) == true) {
                    cycle_detected = true;
                    break;
                }
            }
        }

        if (cycle_detected == true) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}