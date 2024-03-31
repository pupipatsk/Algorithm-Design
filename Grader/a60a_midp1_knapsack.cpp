#include <iostream>
#include <vector>

using namespace std;

int v[505], w[505];
int V[505][505];
vector<int> ans;

void solve(int a, int b) {
    if (V[a][b] == 0) return ;
    else if (V[a][b] == V[a-1][b]) solve(a-1, b);
    else {
        ans.push_back(a);
        solve(a-1, b-w[a]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> V[i][j];
        }
    }

    solve(n, m);

    cout << ans.size() <<"\n";
    for (auto i : ans) cout << i << " ";

    return 0;
}