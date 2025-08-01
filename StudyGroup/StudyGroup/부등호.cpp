#include<iostream>
#include<vector>
#include<string>

using namespace std;

int K;
string line;
vector<string>answer(9);

void recur(int num, string line, vector<string>&ans)
{
	ans[num].push_back(num);
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '<')
		{
			num++;
			if (num > 9)
			{
				return;
			}
			else
			{
				ans[num].push_back(num);
			}
		}
		// >ÀÏ °æ¿ì
		else
		{
			num--;
			if (num < 0)
			{
				return;
			}
			else
			{
				ans[num].push_back(num);
			}
		}
	}
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K;
	
	//cin.ignore(" ");	
	//getline(cin, line);

	for (int i = 0; i < K; i++)
	{
		char str;
		//cin.ignore(' ');
		cin >> str;
		line.push_back(str);
	}

	for(int i=9; i>=0;i--)
	{
		recur(i, line, answer);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << answer[i];
		cout << '\n';
	}

	return 0;
}