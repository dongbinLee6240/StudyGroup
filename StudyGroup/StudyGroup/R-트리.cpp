#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//�������� ����ؼ� �޸� ȿ�� ����
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
		bool ischild = false; //�⺻������ default��
		auto [parent, child] = q.front(); //parent, child (child���� ���� ��� ��ȣ)
		q.pop();
		//t.size���� lower_bound����ؼ� ������ �� ������
		for (int i = 0; i < t.size(); i++)
		{
			//�ڽ��� �������̶�� ���ʿ� ť�� ���� ����
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

	cin >> del; //������ ��ȣ
	bfs(tree, del);

	return 0;
}