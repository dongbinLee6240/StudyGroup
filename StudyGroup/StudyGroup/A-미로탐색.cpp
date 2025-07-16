#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

void bfs(vector<vector<int>> &map, vector<vector<bool>> &visited)
{
	queue<pair<int,int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;

	int N = map.size(); //세로 
	int M = map[0].size(); //가로

	int cnt = 0;
	while (!q.empty())
	{

		for (int i = 0; i < q.size(); i++)
		{
			auto [y, x] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx<0 || nx>=M || ny<0 || ny>=N)
				{
					continue;
				}
				
				if(map[ny][nx] == 1 && !visited[ny][nx]) 
				{
					visited[ny][nx] = true;
					map[ny][nx] = map[y][x] + 1;
					//cnt++;
					q.push({ ny, nx });
				}
			}

		}
	}
	cout << map[N-1][M-1]; //어짜피 마지막 도달하는 곳은 n-1,m-1일 것.
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	string str;

	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		//cin.ignore('\0');
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	bfs(map, visited);

	return 0;
}