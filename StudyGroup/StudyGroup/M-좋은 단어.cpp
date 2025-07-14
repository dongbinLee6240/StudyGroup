#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	int cnt = 0;

	cin >> n;

	string str;
	for (int i = 0; i < n; i++)
	{
		stack<char>s;
		cin >> str;

		int A = count(str.begin(), str.end(), 'A'); //A����
		int B = count(str.begin(), str.end(), 'B');

		if (A % 2 == 1 || B % 2 == 1) //Ȧ���� ���ʿ� �Ұ���
			continue;
		//��� ¦���� �͸� ���ÿ� �߰�

		//ex) ABBA -> A -> AB -> ABB -> pop() -> A -> AA -> pop()
		for (int i = 0; i < str.size(); i++)
		{
			if (s.empty()||s.top()!=str[i]) //����ְų�, ���� �ٸ���
			{
				s.push(str[i]);
			}
			else if (!s.empty() && s.top() == str[i]) //���ÿ� ���� �ְ�, ���ÿ� �ִ� ���� ���ٸ� ���ÿ� �ִ� ���� pop��
			{
				s.pop();
			}

		}

		if (s.empty())
		{
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}