#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Himmel
{
	int Hmax;
	int Hp;
	int Attack;
};

struct room
{
	int type;
	int attack;
	int health;
};

int N;
int t, a, h;
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

    Himmel himmel ;
	cin >> N >> himmel.Attack;

	vector<room>rooms(N);
	for (int i = 0; i < N; i++)
	{
		cin>>rooms[i].type >> rooms[i].attack >> rooms[i].health;
	}

	long long curhealth = 0;
	bool flag = false;
	int dif = 0;
	for (int i = 0; i < N; i++)
	{
		if (rooms[i].type == 1)
		{
			int temp = rooms[i].health / himmel.Attack;
			//curhealth = max(curhealth,rooms[i].attack * temp + 1);
			if (rooms[i].attack * temp + 1 > curhealth)
			{
				curhealth = rooms[i].attack * temp + 1;
			}
		}

		if (rooms[i].type == 2)
		{
			himmel.Attack += rooms[i].attack;
			if (curhealth > rooms[i].health)
			{
				flag = true;
				dif = curhealth - rooms[i].health;
			}
		}
	}

	cout << curhealth;

	return 0;
}