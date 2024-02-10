#include <iostream>
#include <vector>

using namespace std;

void solve(int A, int B, vector<int> &sol,int len, int cnt) {
    if (len < B) {
        sol[len] = 0;
        solve(A,B,sol,len+1,cnt);
        sol[len] = 1;
        solve(A,B,sol,len+1,cnt+1);
    }
    else {
        // print ans
        if (len == B && cnt == A){
            for (int i = 0; i < B; i++) cout << sol[i];
            cout << '\n';
        }
    }
}

int main() {
    int A, B;
    cin >> A >> B;
    vector<int> sol(B);
    solve(A,B,sol,0,0);

    return 0;
}