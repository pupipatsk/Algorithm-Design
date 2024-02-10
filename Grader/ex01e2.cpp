#include <iostream>
#include <vector>

using namespace std;

int mss() {

}

int main() {
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << mss(v, 0, n-1, S);
    
    return 0;
}