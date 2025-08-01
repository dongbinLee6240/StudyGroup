#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int R;
int C;

//아래 오른쪽
static int dx[] = { 1,0,-1,0 };
static int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> swans;

int day = 0;

void resetbool(vector<vector<bool>>& visit) 
{
	//false로 초기화작업
	for (int i = 0; i < R; ++i)
		fill(visit[i].begin(), visit[i].end(), false);
}

bool connect(vector<string>& map, vector<vector<bool>>& visited, int y, int x)
{
	queue<pair<int, int>> swan;
	swan.push({ y,x });

	while (!swan.empty())
	{
		auto [y, x] = swan.front();
		visited[y][x] = true;

	    swan.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R)
				continue;
			if (visited[ny][nx])
				continue;

			// 다른 백조에 도달
			if (map[ny][nx] == 'L')
				return true;

			// 물을 통해 계속 탐색
			if (map[ny][nx] == '.')
			{
				swan.push({ ny,nx });
			}
		}
	}

	return false;
}

void bfs(vector<string>& map,vector<vector<bool>>&visited)
{
	while (true)
	{
		queue<pair<int, int>> q;
		vector<pair<int, int>> melt;

		q.push({ 0, 0 });
		melt.clear();

		while (!q.empty())
		{
			auto [y, x] = q.front();
			visited[y][x] = true;

			q.pop();
			for (int i = 0; i < 2; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= C || ny < 0 || ny >= R)
					continue;
				if (visited[ny][nx] == true)
					continue;

				if (map[ny][nx] == '.')
				{
					if (map[y][x] == 'X')
						melt.push_back({ y,x });
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 'X')
				{
					//X주변에 .이 존재하는지 확인.
					bool near_water = false;
					for (int d = 0; d < 4; ++d)
					{
						int adj_x = nx + dx[d];
						int adj_y = ny + dy[d];
						if (adj_x < 0 || adj_x >= C || adj_y < 0 || adj_y >= R)
							continue;
						if (map[adj_y][adj_x] == '.')
						{
							near_water = true;
							break;
						}
					}
					if (near_water)
						melt.push_back({ ny, nx });

					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 'L')
				{
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}

		resetbool(visited);
		day++;
		for (auto& [y, x] : melt)
		{
			map[y][x] = '.'; // 녹이기
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout<< map[i][j];
			}
			cout << '\n';
		}
		//reset된 visited
		if (connect(map, visited, swans[0].first, swans[0].second))
		{
			break;
		}

	}

	cout << day;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	// R, C를 2만큼 증가시켜서 테두리 확보
	vector<string> lake(R);  // 모두 '.'으로 초기화
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	// 원래 입력을 가운데에 복사
	for (int i = 0; i < R; ++i)
	{
		cin >> lake[i];
		for (int j = 0; j < C; ++j)
		{
			if (lake[i][j] == 'L')
				swans.push_back({ i, j });
		}
	}

	// visited 배열도 크기 맞게 초기화
	bfs(lake, visited);

	return 0;
}