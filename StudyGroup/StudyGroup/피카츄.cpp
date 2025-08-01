#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string str;

	cin >> str;

	bool ispika = true;

	while (str.size())
	{
		if (str[0] == 'p')
		{
			string sub1 = str.substr(0, 2);
			if (sub1 == "pi")
			{
				str = str.substr(2); //인덱스 2부터 문자열 끝까지
			}
			else
			{
				ispika = false;
				break;
			}
		}
		else if (str[0] == 'k')
		{
			string sub2 = str.substr(0, 2);
			if (sub2 == "ka")
			{
				str = str.substr(2);
			}
			else
			{
				ispika = false;
				break;
			}

		}
		else if (str[0] == 'c')
		{
			string sub3 = str.substr(0, 3);
			if (sub3 == "chu")
			{
				str = str.substr(3);
			}
			else
			{
				ispika = false;
				break;
			}
		}

		else
		{
			ispika = false;
			break;
		}
	}

	if (ispika)
	{
		cout << "YES";
	}
	else
		cout << "NO";

	return 0;
}