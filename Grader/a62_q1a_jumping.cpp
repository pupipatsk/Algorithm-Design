#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> B(n+1);
    B[1] = arr[1];
    B[2] = arr[1] + arr[2];
    B[3] = max(B[1], B[2]) + arr[3];
    for (int i = 4; i <= n; i++) {
        B[i] = max(max(B[i-1], B[i-2]), B[i-3]) + arr[i];
    }

    cout << B[n];
    
    return 0;
}