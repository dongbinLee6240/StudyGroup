#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//정수론

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	long long num;
	//무한 루프
	while (1)
	{
		cin >> num;
		string eq;
		int cnt;

		for (int i = 1; ; i++)
		{
			bool confirm = true;
			cnt = 0;
			eq = to_string(num * i); //string으로 변환

			for (int j = 0; j < eq.size(); j++) //기본적으로 confirm은 true
			{
				if (eq[j] == '1')
				{
					cnt++;
				}
				else
					confirm = false; //하나라도 1이 아니면 false 처리
			}

			if (confirm == true)
			{
				break;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}