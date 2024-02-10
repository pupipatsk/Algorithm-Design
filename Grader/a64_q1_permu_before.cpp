#include <iostream>
#include <vector>

using namespace std;

void solve(int n, vector<int> &sol, int len, vector<bool> &used, vector<int> &before) {
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (used[i] == false) {
                if (used[before[i]] || before[i]==-1) {
                    used[i] = true;
                    sol[len] = i;
                    solve(n,sol,len+1,used,before);
                    used[i] = false;
                }
            }
        }
    }
    else {
        for (auto &e : sol) cout << e << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> before(n,-1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        before[b] = a;
    }
    
    vector<int> sol(n);
    vector<bool> used(n);
    solve(n,sol,0,used,before);
    
    return 0;
}