#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

using v_v = vector<vector<int>>;
using v_p = vector<pair<int, int>>;
using v_b = vector<vector<bool>>;

static int dx[] = { 1,0,-1,0 };
static int dy[] = { 0,1,0,-1 };

// 0인 좌표에서 3개 선택
vector<vector<pair<int, int>>> get_combinations(const v_p& positions)
{
	vector<vector<pair<int, int>>> res;
	int N = positions.size();
	vector<int> bitmask(N, 1);
	for (int i = 0; i < 3; ++i)
		bitmask[i] = 0;

	do
	{
		vector<pair<int, int>> selected;
		for (int i = 0; i < N; ++i)
		{
			if (bitmask[i] == 0)
				selected.push_back(positions[i]);
		}
		res.push_back(selected);
	} while (next_permutation(bitmask.begin(), bitmask.end()));

	return res;
}

// 바이러스 퍼뜨리는 DFS
void spread_virus(v_v& map, v_b& visited, int x, int y)
{
	int N = map.size();
	int M = map[0].size();
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		if (map[ny][nx] == 0 && !visited[ny][nx])
		{
			map[ny][nx] = 2; // 바이러스 확산
			spread_virus(map, visited, nx, ny);
		}
	}
}

int count_safe_area(const v_v& map)
{
	int cnt = 0;
	for (const auto& row : map)
		for (int val : row)
			if (val == 0) cnt++;
	return cnt;
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	v_v lab(N, vector<int>(M));
	v_p empty_positions;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 0)
				empty_positions.push_back({ i, j });
		}
	}

	int max_safe = INT_MIN;
	auto wall_combinations = get_combinations(empty_positions);

	for (const auto& walls : wall_combinations)
	{
		v_v copy = lab;
		for (auto [y, x] : walls)
			copy[y][x] = 1; // 벽 설치

		v_b visited(N, vector<bool>(M, false));

		// 바이러스 퍼뜨리기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (copy[i][j] == 2 && !visited[i][j])
					spread_virus(copy, visited, j, i);
			}
		}

		int safe_area = count_safe_area(copy);
		max_safe = max(max_safe, safe_area);
	}

	cout << max_safe << '\n';
	return 0;
}
