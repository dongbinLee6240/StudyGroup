#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	vector<int>matterials(N);
	for (int i = 0; i < N; i++)
	{
		cin >> matterials[i];
	}

	int cnt = 0;

	sort(matterials.begin(), matterials.end());

	/*for (int i = 0; i < 2; i++)
	{
		sum += matterials[i];
		if (sum == M)cnt++;
	}*/

	for (int i = 0; i < N; i++)
	{
		int sum=0;
		for (int j = matterials.size() - 1; j > i; j--)
		{
			//i��°�� ���� �� ���� �� M���� ������ continue�ؼ� ���� M
			if (matterials[i] + matterials[j] < M)
			{
				continue;
			}
			else
			{
				if (matterials[i] + matterials[j] == M)
				{
					cnt++;
				}
			}
		}
	}
	//�������� 2��for�� ���� �ȵ� �� ����

	//while (dif == matterials.size())
	//{
	//	for (int i = start; i < N; i++)
	//	{
	//		//���ӵ� 2���� ���� ���ϴ� ��
	//		sum += matterials[i] - matterials[i - dif];

	//		if (sum == M)
	//		{
	//			cnt++;
	//		}
	//	}
	//}

	
	cout << cnt;

	return 0;
}