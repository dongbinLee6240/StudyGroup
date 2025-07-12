#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int maxheight = 100;

	vector<int> dwarfs(9, 0);

	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		//9���� ������ Ű �Է�
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	//
	sort(dwarfs.begin(), dwarfs.end());
	//���ô� 4 8�� ���� 4�� �����ϸ� 8�� 7�� ��
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - dwarfs[i] - dwarfs[j] == 100)
			{
				dwarfs.erase(dwarfs.begin() + j); //���������� i��°�� ���� dwarfs.size()�� 8�� ��
				dwarfs.erase(dwarfs.begin() + i); //
				break;
			}
		}

		if (dwarfs.size() == 7)
		{
			break;
		}
	}

	for (int i = 0; i < dwarfs.size(); i++)
	{
		cout << dwarfs[i] << '\n';
	}

	return 0;

}