#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int set = 0;
int N, K;
vector<int> wordMasks;
int ans = 0;
void dfs(int idx, int cnt, int mask)
{
	if (cnt == K - 5)
	{
		int readcnt = 0;
		for (int m : wordMasks)
		{
			if ((m & mask) == m)
				readcnt++;
		}
		ans = max(ans, readcnt);
		return;
	}

	for (int i = idx; i < 26; i++) 
	{
		if (mask & (1 << i)) continue; // 이미 아는 글자면 패스
		dfs(i + 1, cnt + 1, mask | (1 << i));
	} 
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	vector<string> words(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> words[i];
	}

	if (K < 5)
	{
		cout << 0;
		return 0;
	}

	if (K == 26)
	{
		cout << N;
		return 0;
	}

	//최소 집합
	set |= (1 << ('a' - 'a'));
	set |= (1 << ('n' - 'a'));
	set |= (1 << ('t' - 'a'));
	set |= (1 << ('i' - 'a'));
	set |= (1 << ('c' - 'a'));

	for (string& w : words) 
	{
		int mask = 0;
		for (char c : w) 
		{
			mask |= (1 << (c - 'a'));
		}
		wordMasks.push_back(mask);
	}

	dfs(0, 0, set);

	cout << ans;

	return 0;
}