#include <iostream>
#include <vector>

using namespace std;

int nonNegativeIdx(int i) {
    if (i < 0) return 0;
    return i;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> arr(n+1, 0); // idx:meter, store #pieces
    int minLength = min(min(a,b),c);
    for (int i = minLength; i <= n; i++) {
        int maxPiece = max(max( arr[nonNegativeIdx(i-a)], arr[nonNegativeIdx(i-b)] ), arr[nonNegativeIdx(i-c)]);
        // cout << i << ":" << maxPiece <<endl;
        if (maxPiece != 0 || i == a || i == b || i == c) arr[i] = maxPiece + 1;
    }
    cout << arr[n];
    
    return 0;
}