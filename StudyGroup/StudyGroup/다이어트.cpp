#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int result = INT_MAX;

int N;
int cp, cf, cs, cv;

struct Ingredients 
{
	int mp, mf, ms, mv, c;
};

int calc_diet(vector<Ingredients>& ig) 
{
	int sump = 0, sumf = 0, sums = 0, sumv = 0, sumc = 0;
	for (auto& i : ig) 
	{
		sump += i.mp;
		sumf += i.mf;
		sums += i.ms;
		sumv += i.mv;
		sumc += i.c;
	}
	if (sump < cp || sumf < cf || sums < cs || sumv < cv) return -1;
	return sumc;
}

vector<vector<Ingredients>> get_combinations(const vector<Ingredients>& positions, int n) 
{
	vector<vector<Ingredients>> res;
	int K = positions.size();
	vector<int> bitmask(K, 1);
	fill(bitmask.begin(), bitmask.begin() + n, 0); // n개 선택

	do 
	{
		vector<Ingredients> selected;
		for (int i = 0; i < K; ++i)
			if (bitmask[i] == 0)
				selected.push_back(positions[i]);
		res.push_back(selected);
	} while (next_permutation(bitmask.begin(), bitmask.end()));

	return res;
}

int main() 
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	cin >> cp >> cf >> cs >> cv;

	vector<Ingredients> ingredients(N);
	for (int i = 0; i < N; i++)
		cin >> ingredients[i].mp >> ingredients[i].mf >> ingredients[i].ms >> ingredients[i].mv >> ingredients[i].c;

	vector<Ingredients> result_comb;
	bool flag = false;

	for (int r = 1; r <= N; r++) 
	{
		auto combinations = get_combinations(ingredients, r);
		for (auto& comb : combinations) 
		{
			int total = calc_diet(comb);
			if (total != -1 && total < result) 
			{
			   result = total;
			   result_comb = comb;
			   flag = true;
				
			}
		}
	}

	// 출력
	if (flag) 
	{
		vector<int> indexes;
		for (auto& ing : result_comb) 
		{
			for (int i = 0; i < N; i++) 
			{
				if (ingredients[i].mp == ing.mp &&
					ingredients[i].mf == ing.mf &&
					ingredients[i].ms == ing.ms &&
					ingredients[i].mv == ing.mv &&
					ingredients[i].c == ing.c) 
				{
					indexes.push_back(i + 1); // 1-based
					break;
				}
			}
		}
		sort(indexes.begin(), indexes.end());
		cout << result << '\n';
		for (int idx : indexes) cout << idx << " ";
	}
	else 
	{
		cout << -1;
	}

	return 0;
}
