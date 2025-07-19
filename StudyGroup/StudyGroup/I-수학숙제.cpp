#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>  // isdigit()

using namespace std;

// 숫자 문자열 정렬 기준: 길이 → 사전순
bool compare(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> str(N);
    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    vector<string> arr;

    for (int i = 0; i < N; i++)
    {
        string temp;
        for (int j = 0; j < str[i].size(); j++)
        {
            if (isdigit(str[i][j]))
            {
                temp.push_back(str[i][j]);
            }
            else
            {
                if (!temp.empty())
                {
                    // 앞의 0 제거
                    while (temp.size() > 1 && temp[0] == '0')
                        temp.erase(temp.begin());
                    arr.push_back(temp);
                    temp.clear();
                }
            }
        }

        // 숫자로 끝나는 경우 처리
        if (!temp.empty())
        {
            while (temp.size() > 1 && temp[0] == '0')
                temp.erase(temp.begin());
            arr.push_back(temp);
            temp.clear();
        }
    }

    sort(arr.begin(), arr.end(), compare);

    for (const auto& s : arr)
    {
        cout << s << '\n';
    }

    return 0;
}
