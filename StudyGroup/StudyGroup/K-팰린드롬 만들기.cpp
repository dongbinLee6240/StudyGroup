#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	//int& 1 <<Ȧ�� üũ

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
		//�� Ȧ��
		if (it.second % 2 != 0)
		{
			cnt++;
		}
	}
	//���ĺ� �߿� Ȧ������ 2�� �̻��� ��� �Ұ���
	if (cnt > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	//map Ư���� �ڿ������� ���ĵ�
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

	//��ȸ ���� �� ���ĺ� ������ ���� �ִ� ��� Ȧ���� ���ĺ�
	//for (auto& it : alpha)
	//{
	//	//Ȧ�� ������ ���ĺ� 
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