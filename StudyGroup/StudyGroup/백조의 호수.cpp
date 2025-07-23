#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int R;
int C;
static int dx[] = { 1,0,-1,0 };
static int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> swans;

bool dfs(vector<string>& map, vector<vector<bool>>visited, int x, int y)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
		{
			continue;
		}
		if (map[ny][nx] == '.' && !visited[ny][nx])
		{
			dfs(map, visited, nx, ny);
		}
		if (map[ny][nx] == 'L' && !visited[ny][nx])
		{
			return true;
		}
	}

	return false;
}

void bfs(vector<string>& map, vector<vector<bool>>& visited)
{
	int time = 0;

	while (true)
	{
		queue<pair<int, int>> q;
		vector<pair<int, int>> melt;
		q.push({ 0, 0 });
		vector<vector<bool>> check_visited(R, vector<bool>(C, false));

		while (!q.empty())
		{
			auto [y, x] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= C || ny < 0 || ny >= R)
					continue;
				if (visited[ny][nx] == true)
					continue;
				if (map[ny][nx] == '.')
				{
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 'X')
				{
					melt.push_back({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}

		if (dfs(map, check_visited, swans[0].first, swans[0].second) == true)
		{
			break;
		}

		for (auto& [y, x] : melt)
			map[y][x] = '.'; // 녹이기

		time++;
	}

	cout << time;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	vector<string> lake(R);
	vector<vector<bool>>visited(R, vector<bool>(C, false));
	vector<vector<bool>>visited_dfs(R, vector<bool>(C, false));
	//vector<vector<char>> map(R, vector<char>(C));

	for (int i = 0; i < R; ++i)
	{
		cin >> lake[i];
		for (int j = 0; j < C; ++j) 
		{
			if (lake[i][j] == 'L')
				swans.push_back({ i, j });
		}
	}

	bfs(lake, visited);

	return 0;
}

//8 17
//...XXXXXX..XX.XXX 
//....XXXXXXXXX.XXX 
//...XXXXXXXXXXXX.. 
//..XXXXX.LXXXXXX.. 
//.XXXXXX..XXXXXX.. 
//XXXXXXX...XXXX... 
//..XXXXX...XXX.... 
//....XXXXX.XXXL... 
//처음              
//....XXXX.......XX
//.....XXXX..X.....
//....XXX..XXXX....
//...XXX....XXXX...
//..XXXX....XXXX...
//..XXXX.....XX....
//....XX.....X.....
//.....XX....X.....
//첫째 날
//
//.....XX..........
//......X..........
//.....X.....X.....
//....X......XX....
//...XX......XX....
//....X............
//.................
//.................
//둘째 날