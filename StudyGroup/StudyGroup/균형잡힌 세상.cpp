#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main()
{
	while (1)
	{
		string str;
		//띄어쓰기 포함
		getline(cin, str);

		stack<char>s;

		if (str == ".")
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == '(' || str[i] == '[')
				{
					s.push(str[i]);
				}
				if (str[i] == ')')
				{
					if (s.empty()||s.top()!='(')
					{
						s.push(str[i]);
					}
					if (s.top() == '(' && !s.empty())
					{
						s.pop();
					}
				}
				if (str[i] == ']')
				{
					if (s.empty()||s.top()!='[')
					{
						s.push(str[i]);
					}
					if (s.top() == '[' && !s.empty())
					{
						s.pop();
					}
				}
			}

			
			if (s.empty())
			{
				cout << "yes" << '\n';
			}
			else
			{
				cout << "no" << '\n';
			}
		}
		
	}
	return 0;
}