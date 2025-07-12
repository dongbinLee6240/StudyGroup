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
		//만약 flag가 마지막에 한에 true가 될 수 있다면. ex)stacks -> s s가 같음
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