#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.first < b.first;
}

int main()
{
	int A, B, C;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	vector<pair<int, int>>trucks(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> trucks[i].first >> trucks[i].second;
	}

	sort(trucks.begin(), trucks.end(), compare);

	int sum = 0;
	int start = trucks[0].first;
	for (int i = 1; i < 3; i++)
	{
		if (trucks[i].first > trucks[i - 1].first && trucks[i].first < trucks[i - 1].second)
		{
			sum += (trucks[i].first - trucks[i - 1].first) * A;
			sum += (trucks[i - 1].second - trucks[i].first) * B;
		}
	}

}