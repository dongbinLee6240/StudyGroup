#include<iostream>
#include<vector>

using namespace std;

void climate()
{

}
int main()
{
	//1분이 지날때마다 1킬로미터씩 동쪽으로 이동한다.
	int H, W;

	cin >> H >> W;

	vector<string> sky(H);

	for (int i = 0; i < H; i++) 
	{
		cin >> sky[i];
	}
	
	for (int i = 0; i < H; i++)
	{
		int time = -1;
		for (int j = 0; j < W; j++)
		{
			if (sky[i][j] == 'c')
			{
				time = 0;
				cout << time << " ";
			}
			else if (sky[i][j] != 'c' && time == -1)
			{
				cout << time << " ";
			}
			else if (sky[i][j] != 'c' && time > -1)
			{
				time += 1;
				cout << time << " ";
			}
		}

		cout << '\n';
	}

	return 0;
}