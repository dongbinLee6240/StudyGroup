#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

void rot13(string str)
{
	vector<int>arr(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		arr[i] = static_cast<int>(str[i]);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= 65 && arr[i] <= 90)
		{
			if (arr[i] + 13 > 90)
			{
				str[i] = static_cast<char>(arr[i] - 13);
			}
			else if (arr[i] + 13 <= 90)
			{
				str[i] = static_cast<char>(arr[i] + 13);
			}
		}
		else if (arr[i] >= 97 && arr[i] <= 122)
		{
			if (arr[i] + 13 > 122)
			{
				str[i] = static_cast<char>(arr[i] - 13);
			}
			else if (arr[i] + 13 <= 122)
			{
				str[i] = static_cast<char>(arr[i] + 13);
			}
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string str;

	getline(cin, str);

	rot13(str);

	return 0;
}