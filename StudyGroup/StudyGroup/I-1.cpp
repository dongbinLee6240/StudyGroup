#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//������

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	long long num;
	//���� ����
	while (1)
	{
		cin >> num;
		string eq;
		int cnt;

		for (int i = 1; ; i++)
		{
			bool confirm = true;
			cnt = 0;
			eq = to_string(num * i); //string���� ��ȯ

			for (int j = 0; j < eq.size(); j++) //�⺻������ confirm�� true
			{
				if (eq[j] == '1')
				{
					cnt++;
				}
				else
					confirm = false; //�ϳ��� 1�� �ƴϸ� false ó��
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