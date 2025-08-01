#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, K;
int answer = 0;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void dfs(vector<string>& map, vector<vector<bool>>& visited,
    int x, int y, int cnt) 
{
    if (x == C - 1 && y == 0) 
    { // 도착지점 (0, C-1)
        if (cnt == K) answer++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) 
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R)
            continue;
        if (visited[ny][nx] || map[ny][nx] == 'T')
            continue;

        visited[ny][nx] = true;
        dfs(map, visited, nx, ny, cnt + 1);
        visited[ny][nx] = false; // 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> K;
    vector<string> map(R);
    for (int i = 0; i < R; ++i)
        cin >> map[i]; // 수정: getline → cin

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[R - 1][0] = true;

    dfs(map, visited, 0, R - 1, 1); // 시작점: (R-1, 0), cnt=1

    cout << answer << "\n";
    return 0;
}
