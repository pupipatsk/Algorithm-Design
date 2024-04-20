#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void solve(int remainSum, int num) {
    if (remainSum < num) return;
    ans++;
    for (int put = num; put <= remainSum; put++) {
        solve(remainSum-put, put);
    }
}

int main() {
    int n;
    cin >> n;
    solve(n, 1);
    cout << ans;

    return 0;
}