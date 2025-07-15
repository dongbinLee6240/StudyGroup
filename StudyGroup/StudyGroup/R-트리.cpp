#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//전역변수 사용해서 메모리 효율 증가
int N;
int node;
int del;
int root;

void bfs(vector<pair<int,int>>t,int del)
{
	queue<pair<int, int>> q;

	int cnt = 0;
	/*q.push(t.front());*/

	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].first == -1)
		{
			if (t[i].second == del)
			{
				cout << 0;
				return;
			}
			q.push({ t[i].first,t[i].second });
		}
	}

	while (!q.empty())
	{
		bool ischild = false; //기본적으로 default값
		auto [parent, child] = q.front(); //parent, child (child값이 현재 노드 번호)
		q.pop();
		//t.size에서 lower_bound사용해서 갯수를 뺀 값까지
		for (int i = 0; i < t.size(); i++)
		{
			//자식이 삭제값이라면 애초에 큐에 넣지 않음
			if (t[i].first == child && t[i].second != del)
			{
				q.push({ t[i].first,t[i].second });
				ischild = true;
			}
			
		}
		if (ischild == false)
		{
			cnt++;
		}
	}

	std::cout << cnt;
}
int main()
{
	cin.tie(0); 
    std:: cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<pair<int, int>> tree(N);

	for (int i = 0; i <N; i++)
	{
		cin >> node;
		tree[i] = { node,i };
	}

	cin >> del; //삭제할 번호
	bfs(tree, del);

	return 0;
}