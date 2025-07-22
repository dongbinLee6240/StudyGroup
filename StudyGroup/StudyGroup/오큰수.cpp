#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> answer(N);
	stack<int> s;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 뒤에서부터 오른쪽 원소들을 확인
	for (int i = N - 1; i >= 0; i--)
	{
		// 자신보다 작거나 같은 값은 스택에서 제거
		while (!s.empty() && s.top() <= arr[i])
			s.pop();

		// 스택이 비어있으면 오큰수가 없음
		if (s.empty())
			answer[i] = -1;
		else
			answer[i] = s.top();

		// 현재 원소를 스택에 push
		s.push(arr[i]);
	}

	// 결과 출력
	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";

	return 0;
}
