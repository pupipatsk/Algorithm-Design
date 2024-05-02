#include <iostream>

using namespace std;

int n;
int ans = 0;
int queen[20]; // [row, row, ...]

bool check(int col, int row) {
    for (int c = 1; c < col; c++) {
        if (queen[c] == row) return false; // same row
        if (abs(queen[c]-row) == abs(c-col)) return false; // same diag
    }
    return true;
}

void solve(int col) {
    if (col > n) {
        ans++;
        return;
    }

    for (int row = 1; row <= n; row++) {
        if (!check(col, row)) continue;
        queen[col] = row;
        solve(col+1);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) queen[i] = 1e9;
    solve(1);
    cout << ans;

    return 0;
}