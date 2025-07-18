#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<string> str;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		string temp;
		for (int j = 0; j < str[i].size(); j++)
		{
			if (isdigit(str[i][j]))
			{
				temp.push_back(str[i][j]);
			}
			else if (!isdigit(str[i][j]) && !temp.empty())
			{
				arr.push_back(stoi(temp));
			}
		}
		
	}
}