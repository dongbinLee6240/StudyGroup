#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool check_gat(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	else
		return false;
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string str;
	while (cin >> str)
	{
		bool is_gather = false;
		bool is_seq_gather = false; //true가 되면 어려운 패스워드
		bool is_seq_consonant = false; //true가 되면 어려운 패스워드
		bool is_same = false;

		//연속 숫자 갯수
		int seq_cnt = 0;
		//연속 모음 갯수
		int gat_cnt = 0;
		//연속 자음 갯수
		int con_cnt = 0;

		//str이 end일경우 종료
		if (str == "end")
		{
			return 0;
		}
		//end가 아닐 경우 -> 순회를 하면서 모음이 있다면 검사 시작
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				//일단 모음이 하나라도 있어야 함.

				if (check_gat(str[i])) //모은지 체크
				{
					is_gather = true;
					con_cnt = 0;
					gat_cnt++;
					if (gat_cnt == 3) //모음이 연속으로 3개 있을 경우
					{
						is_seq_gather = true;
					}
				}

				else //즉 모음이 아니라는 말
				{
					//연속하지 않는다면 cnt값 초기화
					gat_cnt = 0;
					con_cnt++;
					if (con_cnt == 3)
					{
						is_seq_consonant = true;
					}
				}

			}
			for (int i = 0; i < str.size()-1; i++)
			{
				//연속으로 같은 글자가 나오면 안됨
				if (str[i] == str[i + 1])
				{
					//ee or oo
					if ((str[i] == 'e' && str[i + 1] == 'e') || (str[i] == 'o' && str[i + 1] == 'o'))
					{
						continue;
					}
					else
					{
						is_same = true;
					}
				}
			}

		}

		if (is_gather && !is_seq_gather && !is_seq_consonant && !is_same)
		{
			cout << "<" << str << "> is acceptable." << '\n';
		}
		//하나라도 조건에 어긋난다면
		else
		{
			cout << "<" << str << "> is not acceptable." << '\n';
		}
	}
	return 0;
}