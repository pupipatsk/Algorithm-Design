#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    while (m--)
    {
        int x; cin >> x;
        int ans = -1, start = 0, stop = n-1;
        while (start <= stop)
        {
            int mid = (start + stop) / 2;
            if (x >= v[mid]){
                start = mid + 1;
                ans = mid;
            } 
            else {
                stop = mid - 1;
            }
        }
        cout << ans << '\n';
    }
        
    return 0;
}