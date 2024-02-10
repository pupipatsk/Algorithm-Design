#include <iostream>
#include <vector>

using namespace std;

void solve(int n, vector<int> &sol, int len, bool trig, int cnt, int k) {
    if (len < n) {
        if (cnt >= k) trig = true;

        sol[len] = 0;
        solve(n,sol,len+1,trig,0,k);
        sol[len] = 1;
        solve(n,sol,len+1,trig,cnt+1,k);
    } 
    else {
        // print sol
        if (trig || cnt==k) {
            for (int e : sol) cout << e; 
            cout << '\n';
        }
        
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    solve(n,sol,0,false,0,k);
    
    return 0;

}