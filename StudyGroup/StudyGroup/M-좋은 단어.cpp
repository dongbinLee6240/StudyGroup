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

		int A = count(str.begin(), str.end(), 'A'); //A갯수
		int B = count(str.begin(), str.end(), 'B');

		if (A % 2 == 1 || B % 2 == 1) //홀수면 애초에 불가능
			continue;
		//모두 짝수인 것만 스택에 추가

		//ex) ABBA -> A -> AB -> ABB -> pop() -> A -> AA -> pop()
		for (int i = 0; i < str.size(); i++)
		{
			if (s.empty()||s.top()!=str[i]) //비어있거나, 값이 다르면
			{
				s.push(str[i]);
			}
			else if (!s.empty() && s.top() == str[i]) //스택에 값이 있고, 스택에 있는 값이 갔다면 스택에 있는 값을 pop함
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