#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool judge(pair<char,int>a)
{
	if (a.second < 5)
	{
		return true; //삭제할 값
	}
	return false;
}

bool compare(pair<char,int>a,pair<char,int>b)
{
	return a.first < b.first;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;

	vector<string>names(N);
	unordered_map<char, int>list;
	vector<pair<char, int>>lists;
	vector<pair<char, int>>cnt(26); //cnt[0]= (a,개수)

	int a = 97;
	for (int i = 0; i < 26; i++)
	{
		cnt[i].first = static_cast<char>(a + i);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> names[i];
		//list[names[i][0]] += 1;
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j].first == names[i][0])
			{
				cnt[j].second += 1;
				break;
			}
		}
	}

	cnt.erase(remove_if(cnt.begin(), cnt.end(), judge), cnt.end());

	sort(cnt.begin(), cnt.end(), compare);

	if (cnt.size() > 0)
	{
		for (int i = 0; i < cnt.size(); i++)
		{
			cout << cnt[i].first;
		}
	}
	else
	{
		cout << "PREDAJA";
	}

	return 0;
}