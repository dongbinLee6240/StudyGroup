#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arrive;
int check;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> arrive >> check;
		v.push_back({ arrive,check });
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		// 현재 시각이 소의 도착 시각보다 작으면 기다려야 함
		sum = max(sum, v[i].first) + v[i].second;
	}

	cout << sum;

	return 0;

}