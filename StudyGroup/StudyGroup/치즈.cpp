#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using v_v = vector<vector<int>>;
using v_b = vector<vector<bool>>;

static int dx[] = { 1,0,-1,0 };
static int dy[] = { 0,1,0,-1 };

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	v_v map(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int time = 0;
	int last_cheese = 0;

	while (true)
	{
		v_b visited(N, vector<bool>(M, false));
		queue<pair<int, int>> q;
		vector<pair<int, int>> to_melt;

		// 1. 외부 공기부터 BFS 시작
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty())
		{
			auto [y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx])
					continue;

				if (map[ny][nx] == 0)
				{
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 1)
				{
					// 외부 공기와 맞닿은 치즈
					to_melt.push_back({ ny, nx });
					visited[ny][nx] = true; // 한번만 처리
				}
			}
		}

		if (to_melt.empty())
			break; // 치즈가 모두 녹았으면 종료

		last_cheese = to_melt.size();

		for (auto& [y, x] : to_melt)
			map[y][x] = 0; // 녹이기

		time++;
	}

	cout << time << '\n' << last_cheese << '\n';
	return 0;
}
