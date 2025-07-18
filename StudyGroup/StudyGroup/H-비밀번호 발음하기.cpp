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
		bool is_seq_gather = false; //true�� �Ǹ� ����� �н�����
		bool is_seq_consonant = false; //true�� �Ǹ� ����� �н�����
		bool is_same = false;

		//���� ���� ����
		int seq_cnt = 0;
		//���� ���� ����
		int gat_cnt = 0;
		//���� ���� ����
		int con_cnt = 0;

		//str�� end�ϰ�� ����
		if (str == "end")
		{
			return 0;
		}
		//end�� �ƴ� ��� -> ��ȸ�� �ϸ鼭 ������ �ִٸ� �˻� ����
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				//�ϴ� ������ �ϳ��� �־�� ��.

				if (check_gat(str[i])) //������ üũ
				{
					is_gather = true;
					con_cnt = 0;
					gat_cnt++;
					if (gat_cnt == 3) //������ �������� 3�� ���� ���
					{
						is_seq_gather = true;
					}
				}

				else //�� ������ �ƴ϶�� ��
				{
					//�������� �ʴ´ٸ� cnt�� �ʱ�ȭ
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
				//�������� ���� ���ڰ� ������ �ȵ�
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
		//�ϳ��� ���ǿ� ��߳��ٸ�
		else
		{
			cout << "<" << str << "> is not acceptable." << '\n';
		}
	}
	return 0;
}