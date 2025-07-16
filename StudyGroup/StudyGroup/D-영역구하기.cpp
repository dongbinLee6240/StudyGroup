#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static int dx[] = { 0,-1,0,1 };
static int dy[] = { -1,0,1,0 };

int dfs(vector<vector<int>>&map,vector<vector<bool>>&visited,
	int x, int y)
{
	int cnt = 1;
	int v_size = map.size();
	int h_size = map[0].size();
	
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= h_size || ny < 0 || ny >= v_size)
		{
			continue;
	    }
	    if (map[ny][nx] == 1 && !visited[ny][nx])
	    {
		   cnt+=dfs(map, visited, nx, ny);
		   
	    }  
	
	}

	return cnt;
	
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int M, N, K;
	int area = 0;
	int cnt = 0;
	//M�� ����, N�� ����
	cin >> M >> N >> K; 

	//���簢�� K���� �غ� �������� ����
	vector<pair<int, int>> s_sqaure(K); 

	//�⺻������ 1�� ����
	vector<vector<int>> monun(M, vector<int>(N, 1)); 
	vector<vector<bool>> visited(M, vector<bool>(N,false));
	
	//���簢�� K���� �غ� ������ ����
	vector<pair<int, int>> e_sqaure(K); 
	for (int i = 0; i < K; i++)
	{
		int sx, sy, ex, ey; //start x,y / end x,y
		cin >> sx >> sy >> ex >> ey;
		s_sqaure[i] = { sx,sy };
		e_sqaure[i] = { ex,ey };
	}

	for (int i = 0; i < K; i++)
	{
		for (int j = s_sqaure[i].first; j < e_sqaure[i].first; j++)
		{
			for (int k = s_sqaure[i].second; k < e_sqaure[i].second; k++)
			{
				visited[k][j] = true; //�̸� true�� ����
			}
		}
	}
	vector<int>width;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (monun[i][j] == 1 && visited[i][j] == false)
			{
				width.push_back(dfs(monun, visited,j,i));
				area++;
			}
		}
	}
	
	cout << area << '\n';
	sort(width.begin(), width.end());

	for (auto it : width)
	{
		cout << it << " ";
	}

	return 0;
}