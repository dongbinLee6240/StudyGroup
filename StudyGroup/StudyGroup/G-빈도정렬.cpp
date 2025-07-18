#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool compare(pair<int,int>a, pair<int,int>b)
{
	return a.second > b.second;
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, C;

	cin >> N >> C;
	//unordered_map을 사용해 자동으로 정렬되지 않게 만듬
	//unordered_map<int, int>pass;  -----> map으로 만들었는데 입력이 좀 이상하게 됨
	vector<pair<int, int>> pass;
	for (int i = 0; i < N; i++)
	{
		bool push = false;
		int num;
		cin >> num;
		if (pass.empty())
		{
			pass.push_back({ num,1 });  //pass[i]={num,1};
		}

		else
		{
			for (int j = 0; j < pass.size();j++)
			{
				if (pass[j].first == num)
				{
					pass[j].second += 1;
					push = true;
					break;
				}
			}
			if (!push)
			{
				pass.push_back({ num,1 });
			}
		}
		
	}

	//vector<pair<int, int>> frequent(pass.begin(), pass.end());
	std::stable_sort(pass.begin(), pass.end(), compare);

	for (auto& it : pass)
	{
		for (int i = 0; i < it.second; i++)
		{
			cout << it.first << " ";
		}
	}

	return 0;
}

//int main()
//{
//	cin.tie(0); cout.tie(0);
//	ios::sync_with_stdio(false);
//	
//	int N, C;
//	
//	cin >> N >> C;
//	//unordered_map을 사용해 자동으로 정렬되지 않게 만듬
//	unordered_map<int, int>pass;  
//
//	for (int i = 0; i < N; i++)
//	{
//		int num;
//		cin >> num;
//
//		pass[num] += 1;
//	}
//
//	vector<pair<int, int>> frequent(pass.begin(), pass.end());
//	std::stable_sort(frequent.begin(), frequent.end(), compare);
//
//	for (auto& it : frequent)
//	{
//		for (int i = 0; i < it.second; i++)
//		{
//			cout << it.first << " ";
//		}
//	}
//}