#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<string> map;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

// BFS 함수: 시작점에서 가장 먼 거리 반환
int bfs(int sy, int sx) 
{
    vector<vector<int>> visited(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    visited[sy][sx] = 0;

    int max_dist = 0;

    while (!q.empty()) 
    {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) 
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) 
                continue;
            if (map[ny][nx] != 'L' || visited[ny][nx] != -1) 
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            max_dist = max(max_dist, visited[ny][nx]);
            q.push({ ny, nx });
        }
    }

    return max_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    map.resize(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> map[i];
    }

    int answer = 0;

    // 모든 육지 좌표에서 BFS
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == 'L') 
            {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
