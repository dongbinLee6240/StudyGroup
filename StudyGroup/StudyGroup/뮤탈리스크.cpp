#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int cnt = 0;
int dp[] = { 12,10,4 };

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<int> scv(N);
	int damage[] = { 9,3,1 };
	for (int i = 0; i < N; i++)
	{
		cin >> scv[i];
	}

	while (1)
	{
		bool alldeath = true;
		sort(scv.begin(), scv.end(), greater());

		if (scv.size() == 3 && scv[0] <=12 && scv[1] <= 10 && scv[2] <=4
			&&scv[0]>9&&scv[1]>3&&scv[2]>1)
		{
			cnt += 2;
			break;
		}
		
		for (int i = 0; i < scv.size(); i++)
		{
			scv[i]=scv[i] - damage[i];	
		}
		cnt++;
		for (int i = 0; i < scv.size(); i++)
		{
			if (scv[i] > 0)
			{
				alldeath = false;
			}
		}

		if (alldeath)
			break;
	}

	cout << cnt;

	return 0;
}