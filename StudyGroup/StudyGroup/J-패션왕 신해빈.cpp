#include<iostream>
#include<vector>
#include<string>
#include <map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		//vector<vector<string>>fashion(n, vector<string>());
		map<string, int>fashion;

		string name;
		string types;

		for (int i = 0; i < n; i++)
		{
			cin >> name >> types;
			fashion[types] += 1;
		}
		
		int sum = 1;

		//ex) 1 -> 3(1*(2+1)) -> 6(3*(1+1)) -> 6-1
		for (auto& it : fashion)
		{
			sum *= (it.second + 1); //���Դ´ٴ� ������ +1
		}

		//-1�� �ϴ� ����: �˸� �����̸� �ȵǴϱ�
		cout << sum - 1 << '\n';
		
	}

	return 0;
}