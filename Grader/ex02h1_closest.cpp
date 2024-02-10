#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    
    return 0;
}