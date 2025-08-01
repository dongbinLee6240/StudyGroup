#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

int T;
string str;
string func;
int arrsize;
string arr;
string input;

//역순 큐를 스택으로 넣고 다시 큐로
queue<int> R(queue<int>& q)
{
	stack<int>s;
	queue<int>ret;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		int a = q.front();
		q.pop();
		s.push(a);
	}

	for (int i = 0; i < n; i++)
	{
		int b = s.top();
		s.pop();
		ret.push(b);
	}

	return ret;
}

//디큐
queue<int> D(queue<int>&q)
{
	q.pop();
	return q;
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> func;
		cin >> arrsize;
		queue<int>q;
		cin >> input;
		for (int i = 0; i < input.size();i++)
		{
			if (isdigit(input[i]))
			{
				q.push(input[i]-'0');
			}
		}

		

		if (func.size() > arrsize)
		{
			cout << "error" << '\n';
		}
		else
		{
			while (func.size())
			{
				if (func[0] == 'R')
				{
					func = func.substr(1);
					q = R(q);
				}
				else if (func[0] == 'D')
				{
					func = func.substr(1);
					q = D(q);
				}
			}

			cout << "[";
			while (!q.empty()) 
			{
				int ans = q.front();
				q.pop();
				cout << ans;
				if (!q.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}