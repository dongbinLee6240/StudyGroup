#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int num = 666; // 시작 숫자
    int count = 1; // 666부터 시작이므로 첫 번째

    while (true)
    {
        //만약 숫자에 666이 연속되어 있다면 count++
        //문자열에 666이 없다면 npos 반환
        if (to_string(num).find("666") != string::npos)  // "666"이 포함되어 있다면
        {
            if (count == N)
            {
                cout << num << '\n';
                break;
            }
            count++;
        }
        num++;
    }

    return 0;
}
