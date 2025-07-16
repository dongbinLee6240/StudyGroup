#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

static int dx[] = { 0,-1,0,1 };
static int dy[] = { -1,0,1,0 };

void dfs(vector<vector<int>>&map,vector<vector<bool>>&visited,int y,int x,int rain)
{
	visited[y][x] = true;
	int size = map.size();
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= size || ny < 0 || ny >= size)
			continue;
		if (map[ny][nx] > rain && visited[ny][nx] == false)
		{
			dfs(map, visited, ny, nx, rain);
		}
	}
	
}
int main()
{
	int N;
	int area = 0;
	int max_val = INT_MIN;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<vector<int>>map(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			max_val = max(max_val, map[i][j]);
		}
	}
	vector<int> areas(max_val, 0); //최댓값들을 저장할 장소
	while (max_val--)
	{
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		area = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > max_val && visited[i][j] == false)
				{
					dfs(map, visited, i, j, max_val);
					area++;
				}
			}
		}
		areas[max_val] = area;
	}

	sort(areas.begin(), areas.end(), greater());

	cout << areas[0];

	return 0;
}