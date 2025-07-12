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
		//9명의 난쟁이 키 입력
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	//
	sort(dwarfs.begin(), dwarfs.end());
	//예시는 4 8을 삭제 4를 삭제하면 8은 7이 됨
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - dwarfs[i] - dwarfs[j] == 100)
			{
				dwarfs.erase(dwarfs.begin() + j); //정상적으로 i번째를 지움 dwarfs.size()는 8이 됨
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