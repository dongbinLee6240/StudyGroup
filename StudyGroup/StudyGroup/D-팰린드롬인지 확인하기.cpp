#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string str;
	int cnt = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == str[str.size() - i-1]) //ex) str[0] = str[str.size()]
		{
			cnt++;
		}
		//���� flag�� �������� �ѿ� true�� �� �� �ִٸ�. ex)stacks -> s s�� ����
		else if (str[i] != str[str.size() - i])
		{
			continue;
		}
	}

	if (cnt==str.size())
	{
		cout << 1;
	}
	else
		cout << 0;

	return 0;
}