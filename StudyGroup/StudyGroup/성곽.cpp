#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int castle[51][51]; // 벽 정보
int room[51][51];   // 방 번호
int dx[4] = { -1, 0, 1, 0 }; // 서, 북, 동, 남
int dy[4] = { 0, -1, 0, 1 };
int wallMask[4] = { 1, 2, 4, 8 };
vector<int> roomSize;

int bfs(int sy, int sx, int roomNum) {
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    room[sy][sx] = roomNum;
    int cnt = 1;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if (room[ny][nx] != 0) continue; // 이미 방문한 칸

            // 벽이 있는지 체크
            if (castle[y][x] & wallMask[dir]) continue; // 벽이 있으면 이동 불가

            room[ny][nx] = roomNum;
            q.push({ ny, nx });
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> castle[i][j];

    int roomCount = 0;
    int maxRoomSize = 0;

    // 1. 방 찾기
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (room[i][j] == 0) 
            {
                roomCount++;
                int size = bfs(i, j, roomCount);
                roomSize.push_back(size);
                maxRoomSize = max(maxRoomSize, size);
            }
        }
    }

    // 2. 벽 제거 후 최대 방 크기
    int maxMerged = 0;
    for (int y = 0; y < M; y++) 
    {
        for (int x = 0; x < N; x++) 
        {
            // 동쪽
            if (x + 1 < N && (castle[y][x] & 4)) 
            {
                int a = room[y][x] - 1;
                int b = room[y][x + 1] - 1;
                if (a != b) 
                    maxMerged = max(maxMerged, roomSize[a] + roomSize[b]);
            }
            // 남쪽
            if (y + 1 < M && (castle[y][x] & 8)) 
            {
                int a = room[y][x] - 1;
                int b = room[y + 1][x] - 1;
                if (a != b) 
                    maxMerged = max(maxMerged, roomSize[a] + roomSize[b]);
            }
        }
    }

    cout << roomCount << "\n";
    cout << maxRoomSize << "\n";
    cout << maxMerged << "\n";
}
