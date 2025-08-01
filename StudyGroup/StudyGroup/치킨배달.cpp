#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int N, M;
int result = INT_MAX;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

vector<pair<int, int>> chicken;
vector<vector<int>> city;

bool Isin(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

// 치킨집 M개를 고르는 조합 생성
vector<vector<pair<int, int>>> get_combinations(const vector<pair<int, int>>& positions) 
{
	vector<vector<pair<int, int>>> res;
	int K = positions.size();
	vector<int> bitmask(K, 1);
	for (int i = 0; i < M; ++i)
		bitmask[i] = 0;

	do {
		vector<pair<int, int>> selected;
		for (int i = 0; i < K; ++i) {
			if (bitmask[i] == 0)
				selected.push_back(positions[i]);
		}
		res.push_back(selected);
	} while (next_permutation(bitmask.begin(), bitmask.end()));
	return res;
}

// 선택된 치킨집 조합으로부터 도시 치킨 거리 계산
int chicke_dist(const vector<pair<int, int>>& selected) 
{
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> q;

	// 모든 선택된 치킨집에서 BFS 시작
	for (auto [y, x] : selected) 
	{
		q.push({ y, x });
		dist[y][x] = 0;
	}

	while (!q.empty()) 
	{
		auto [y, x] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!Isin(nx, ny) || dist[ny][nx] != -1) 
				continue;
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	int sum = 0;
	// 각 집에서 가장 가까운 치킨집 거리 누적
	for (int i = 0; i < N; ++i) 
	{
	
		for (int j = 0; j < N; ++j) 
		{
			if (city[i][j] == 1) 
			{
				sum += dist[i][j];
			}
		}
	}
	return sum;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	city = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	auto combinations = get_combinations(chicken);
	for (auto& comb : combinations) 
	{
		int total = chicke_dist(comb);
		result = min(result, total);
	}

	cout << result << '\n';
	return 0;
}
