#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input, boom;
    cin >> input >> boom;

    string result;
    int blen = boom.size();

    for (char c : input) 
    {
        result.push_back(c);

        // 폭발 문자열 체크
        if (result.size() >= blen &&
            result.substr(result.size() - blen) == boom) 
        {
            result.erase(result.size() - blen);
        }
    }

    if (result.empty())
        cout << "FRULA";
    else
        cout << result;
}
