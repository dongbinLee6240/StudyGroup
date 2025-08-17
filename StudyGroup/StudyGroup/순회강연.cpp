#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
	int n; cin >> n;
	vector <pair<int, int>> v;
	priority_queue <int, vector<int>, greater<int>> q; //우선순위 큐.min heap
	int p, d;
	for (int i = 0; i < n; i++) 
	{
		cin >> p >> d;
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end()); //날짜 오름차순대로 정렬
	for (int i = 0; i < n; i++) 
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
}