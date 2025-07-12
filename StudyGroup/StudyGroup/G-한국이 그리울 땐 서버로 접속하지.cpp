#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string pattern;

	cin >> N;
	cin >> pattern;

	vector<string>str(N);
	bool isstar = false;
	string front;
	string end;

	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	int star = pattern.find('*');
	front = pattern.substr(0, star); //0~star
	end = pattern.substr(star + 1);

	vector<string>ans(N);
	vector<int>cnt(N,0);
	for (int i = 0; i < N; i++)
	{
		if (str[i].size() < front.size() + end.size())
		{
			cnt[i]=0;
			continue;
		}
		for (int j = 0; j < front.size(); j++)
		{
			if (str[i][j] == front[j])
			{
				cnt[i]++;
			}
			
		}
		for (int k = 0; k < end.size(); k++)
		{
			if (str[i][str[i].size() - end.size()+k] == end[k])
			{
				cnt[i]++;
			}
			
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == front.size() + end.size())
		{
			cout << "DA" << '\n';
		}
		else
		{
			cout << "NE" << '\n';
		}
	}
	return 0;
}