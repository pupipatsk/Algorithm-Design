#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> c(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    vector<int> arr(n+1);
    arr[1] = c[1];
    arr[2] = max(c[1], c[2]);
    for (int i = 3; i <= n; i++) {
        arr[i] = max(arr[i-1], arr[i-2] + c[i]);
    }
    cout << arr[n];
    
    return 0;
}