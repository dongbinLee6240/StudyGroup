#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	//int& 1 <<홀수 체크

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string str;

	cin >> str;

	//vector<pair<string, int>>alpha(str.size());

	map<char, int> alpha;

	for (int i = 0; i < str.size(); i++)
	{
		char spell = str[i];
		alpha[spell] += 1;
	}
	int cnt = 0;
	for (auto& it : alpha)
	{
		//즉 홀수
		if (it.second % 2 != 0)
		{
			cnt++;
		}
	}
	//알파벳 중에 홀수값이 2개 이상일 경우 불가능
	if (cnt > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	//map 특성상 자연스럽게 정렬됨
	string half="";
	string reversed;
	string mid;
	for (auto& elem : alpha)
	{
		if (elem.second % 2 == 1)
		{
			mid = elem.first;
		}
		half += string(elem.second / 2, elem.first);
	}
	
	reversed = half;
	reverse(reversed.begin(),reversed.end());

	//순회 했을 때 알파벳 개수가 남아 있는 경우 홀수인 알파벳
	//for (auto& it : alpha)
	//{
	//	//홀수 갯수인 알파벳 
	//	if (it.second > 0)
	//	{
	//		half.push_back(it.first);
	//	}
	//}

	if (!mid.empty())
	{
		cout << half + mid + reversed;
	}
	else
	{
		cout << half + reversed;
	}

	return 0;
}