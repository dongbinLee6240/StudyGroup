#include <iostream>
#include <string>

using namespace std;


//비트마스크로 풀기

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str = "";
    int M, x;

    int S = 0;

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> str;

        if (str == "add")
        {
            cin >> x;
            S |= (1 << x); //1 삽입
        }

        else if (str == "remove")
        {
            cin >> x;
            S &= ~(1 << x);  //&= -> ~가 있다면 ~(1<<x) -> 1삭제
        }
        else if (str == "check") {
            cin >> x;
            if (S & (1 << x))   //있으면
            {
                cout << "1\n";  // 1출력
            }
            else
            {
                cout << "0\n";  // 0출력
            }
        }
        else if (str == "toggle")
        {
            cin >> x;
            if (S & (1 << x))
            {  //있으면
                S &= ~(1 << x); //없애고
            }

            else  //없으면
            {
                S |= (1 << x);     //추가
            }
        }
        else if (str == "all")
        {
            S = (1 << 21) - 1;  //21까지 1추가?
        }
        else if (str == "empty")
        {
            S = 0;
        }

    }

    return 0;
}