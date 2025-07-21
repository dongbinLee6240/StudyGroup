#include<iostream>
#include<vector>
#include<string>

using namespace std;
using v_v = vector<vector<int>>;

int cnt_1 = 0;
int cnt_0 = 0;

//start는 시작 x,y좌표, end는 끝나는 x,y좌표
string recur(v_v& v, int x, int y, int size)
{
	int first = v[x][y];
	bool allSame = true;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (v[i][j] != first)
			{
				allSame = false;
				break;
			}
		}
		if (!allSame) break;
	}

	if (allSame)
	{
		return to_string(first);  // "0" or "1"
	}
	else
	{
		int newSize = size / 2;
		string result = "(";
		result += recur(v, x, y, newSize); // 왼쪽 위
		result += recur(v, x, y + newSize, newSize); // 오른쪽 위
		result += recur(v, x + newSize, y, newSize); // 왼쪽 아래
		result += recur(v, x + newSize, y + newSize, newSize); // 오른쪽 아래
		result += ")";
		return result;
	}
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	v_v video(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < N; j++)
		{
			video[i][j] = line[j] - '0';  // '0' → 0
		}
	}

	cout << recur(video, 0, 0, N);
	return 0;
}
