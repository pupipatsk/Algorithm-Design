#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool solve(vector<int> &v, int l, int r) {
    // Base Case: virus length 2
    if (r-l == 1) return true;

    int mid = (l+r) / 2;
    
    bool isConcat = solve(v, l, mid) && solve(v, mid+1, r);

    int cnt1 = 0, cnt2 = 0;
    for (int i = l; i <= mid; i++) cnt1 += v[i];
    for (int i = mid+1; i <= r; i++) cnt2 += v[i];
    
    bool notExceed = false;
    if (abs(cnt1-cnt2) <= 1) notExceed = true;
    
    return isConcat && notExceed;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        
        vector<int> v(pow(2,k));
        for (int j = 0; j < pow(2,k); j++) cin >> v[j];
        
        if (solve(v,0,pow(2,k)-1)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}