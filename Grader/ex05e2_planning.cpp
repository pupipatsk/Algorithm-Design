#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1005];
int indegree[1005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        indegree[i] = m;
        while (m--)
        {
            int x;
            cin >> x;
            adj[x].push_back(i); // x:1 -> i:0
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << ' ';

        for (auto v : adj[u])
        {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    return 0;
}