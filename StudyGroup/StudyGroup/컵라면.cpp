#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int dead;
int ramen;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<pair<int, int>> v;
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++)
	{
		cin >> dead >> ramen;
		v.push_back({ dead,ramen });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		q.push(v[i].second);
		if (q.size() > v[i].first)
		{
			q.pop();
		}
	}

	int sum = 0;
	while (!q.empty())
	{
		sum += q.top();
		q.pop();
	}
	cout << sum;

	return 0;
}