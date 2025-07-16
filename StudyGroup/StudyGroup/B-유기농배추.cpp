#include <iostream>
#include <vector>

using namespace std;

static int dy[] = { -1, 0, 1, 0 };
static int dx[] = { 0, -1, 0, 1 };

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int y, int x, int N, int M) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (map[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(map, visited, ny, nx, N, M);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> map(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int worm_count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(map, visited, i, j, N, M);
                    worm_count++;
                }
            }
        }

        cout << worm_count << '\n';
    }

    return 0;
}