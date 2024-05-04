#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> Adj;
vector<vector<int>> W;
bool found = false;

void dfs(int current_node, vector<int> &prev, int current_sum, int k) {
    if (found) return ;

    cout << "\ncurrent_node: "<<current_node;
    for (auto next_node : Adj[current_node]) {
        if (prev[next_node] == -1) {
            cout <<current_node<<next_node<<"sum:"<<current_sum<<endl;
            int next_sum = current_sum + W[current_node][next_node];
            if (next_sum == k) {
                found = true;
                return ;
            }
            else if (next_sum > k) {
                vector<int> clear_prev(n, -1);
                prev = clear_prev;
                prev[current_node] = current_node;
                continue;
            }

            prev[next_node] = current_node;
            dfs(next_node, prev, next_sum, k);
        }
    }
}

int main()
{
    cin >> n >> m;

    vector<int> K(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> K[i];
    }

    Adj.resize(n);
    W.resize(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
        W[a][b] = w;
        W[b][a] = w;
    }

    for (int i = 0; i < 8; i++)
    {
        found = false;
        for (int start_node = 0; start_node < n; start_node++)
        {
            if (found) break;

            cout << "\nstart_node: " << start_node;
            vector<int> prev(n, -1);
            prev[start_node] = start_node;
            dfs(start_node, prev, 0, K[i]);
        }

        cout << "i: "<< i << " K[i]: "<<K[i];
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}