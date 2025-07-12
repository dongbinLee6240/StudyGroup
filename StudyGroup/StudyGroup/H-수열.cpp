#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> temper(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> temper[i];
	}

	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		sum += temper[i];
	}

	int max_sum = sum;

	//sum은 처음 K개의 합
	//ex) 1, 1 + (temper[2] - temper[0])= - 6,
	for (int i = K; i < N; i++)
	{
		sum += temper[i] - temper[i - K];
		max_sum = max(max_sum, sum);
	}

	cout << max_sum;

	return 0;
}
