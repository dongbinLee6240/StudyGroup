#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int J;
	cin >> J;

	vector<int> apples(J);
	for (int i = 0; i < J; i++)
	{
		cin >> apples[i];
	}

	int cnt = 0;
	int left = 1; //처음 바구니의 왼쪽 끝은 1
	int right = M; //처음 바구니의 오른쪽 끝은 M

	for (int i = 0; i < J; i++)
	{
		if (apples[i] < left) //바구니의 왼쪽
		{
			// 사과가 왼쪽에 떨어지면 바구니 왼쪽으로 이동
			cnt += (left - apples[i]);
			right -= (left - apples[i]);
			left = apples[i];
		}
		else if (apples[i] > right) //바구니의 오른쪽
		{
			// 사과가 오른쪽에 떨어지면 바구니 오른쪽으로 이동
			cnt += (apples[i] - right);
			left += (apples[i] - right);
			right = apples[i];
		}
		// 사과가 바구니 안에 있으면 이동 없음
	}

	cout << cnt;
	return 0;
}