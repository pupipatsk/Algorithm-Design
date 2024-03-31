#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10005];
bool visited[10005];

void dfs(int u) {
    for (auto v : adj[u]) {
        if (visited[v] == false) {
            visited[v] = true;
            dfs(v);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (visited[i] == false) {
            visited[i] == true;
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

    return 0;
}