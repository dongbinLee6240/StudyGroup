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
	int left = 1; //ó�� �ٱ����� ���� ���� 1
	int right = M; //ó�� �ٱ����� ������ ���� M

	for (int i = 0; i < J; i++)
	{
		if (apples[i] < left) //�ٱ����� ����
		{
			// ����� ���ʿ� �������� �ٱ��� �������� �̵�
			cnt += (left - apples[i]);
			right -= (left - apples[i]);
			left = apples[i];
		}
		else if (apples[i] > right) //�ٱ����� ������
		{
			// ����� �����ʿ� �������� �ٱ��� ���������� �̵�
			cnt += (apples[i] - right);
			left += (apples[i] - right);
			right = apples[i];
		}
		// ����� �ٱ��� �ȿ� ������ �̵� ����
	}

	cout << cnt;
	return 0;
}