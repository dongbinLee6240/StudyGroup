#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string str;

	cin >> str;

	vector<pair<char, int>>cnt(26); //cnt[0]= (a,°³¼ö)

	int a = 97;
	for (int i = 0; i < 26; i++)
	{
		cnt[i].first = static_cast<char>(a + i);
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			int alpha = str[j];
			if (cnt[i].first == alpha)
			{
				cnt[i].second += 1;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i].second << " ";
	}

	return 0;
}