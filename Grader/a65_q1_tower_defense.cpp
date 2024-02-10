#include <iostream>
#include <vector>

using namespace std;

int n, m, k, w;
int sumh, ans;

void solve(int towerIdx, int dmg,
            vector<int> &p, vector<int> &h, vector<int> &t) {
    
    if (towerIdx == k) {
        ans = min(ans, sumh - dmg);
        return ;
    }
    
    for (int i = 0; i < m; i++) {
        int distance = abs(t[i] - p[i]);
        if (distance <= w && h[i] > 0) {
            h[i]--;
            solve(towerIdx+1,dmg+1, p,h,t);
        }
        else solve(towerIdx+1,dmg, p,h,t);
    }
}

int main() {
    
    cin >> n >> m >> k >> w;

    vector<int> p(n); // monster position
    for (int i = 0; i < m; i++) cin >> p[i];

    vector<int> h(n); // monster health
    for (int i = 0; i < m; i++){
        cin >> h[i];
        sumh += h[i];
    }

    vector<int> t(n); // tower position
    for (int i = 0; i < k; i++) cin >> t[i];
    
    ans = sumh;
    solve(0,0, p,h,t);
    cout << ans;

    return 0;
}