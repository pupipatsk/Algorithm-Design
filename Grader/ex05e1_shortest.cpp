#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int R, C;
char maze[105][105];
int dist[105][105];
int dir_r[5] = {1, 0, 0, -1}; // direction: N E W S
int dir_c[5] = {0, 1, -1, 0};

void dfs(int r, int c) {
    for (int d = 0; d < 4; d++) {
        int new_r = r + dir_r[d];
        int new_c = c + dir_c[d];

        if (new_r < 1 || new_r > R || new_c < 1 || new_c > C) continue;
        if (maze[new_r][new_c] == '#') continue;

        if (dist[new_r][new_c] > dist[r][c] + 1) {
            dist[new_r][new_c] = dist[r][c] + 1;
            dfs(new_r, new_c);
        }
    }
}

int main() {
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> maze[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            dist[r][c] = INF;
        }
    }
    dist[1][1] = 0;

    dfs(1,1);

    cout << (dist[R][C] == INF ? -1 : dist[R][C]);

    return 0;
}