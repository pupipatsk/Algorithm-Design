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

        int ans = -1;
        int l = 0, r = n-1;
        while (l <= r)
        {
            int mid = (l+r) / 2;
            if (x >= v[mid]) {
                l = mid + 1;
                ans = v[mid];
            }
            else r = mid - 1;
        }
        
        cout << ans << '\n';
    }
    

    return 0;
}