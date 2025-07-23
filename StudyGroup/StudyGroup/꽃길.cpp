#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int N;
int result = INT_MAX;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<int>> board;
vector<vector<bool>> visited;

bool canPlace(int y, int x) 
{
    if (visited[y][x]) 
        return false;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
            return false;
    }
    return true;
}

int plant(int y, int x) 
{
    visited[y][x] = true;
    int cost = board[y][x];
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = true;
        cost += board[ny][nx];
    }
    return cost;
}

void remove(int y, int x) 
{
    visited[y][x] = false;
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = false;
    }
}

void dfs(int depth, int sum) 
{
    if (depth == 3) {
        result = min(result, sum);
        return;
    }

    for (int i = 1; i < N - 1; i++) 
    {
        for (int j = 1; j < N - 1; j++) 
        {
            //심을 수 있다면
            if (canPlace(i, j)) 
            {
                //코스트 값을 board[y][x]에 저장함
                int cost = plant(i, j);
                //꽃의 갯수를 증가 
                dfs(depth + 1, sum + cost);
                remove(i, j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    dfs(0, 0);
    cout << result << '\n';

    return 0;
}
