#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    long long num;
    while (cin >> num) 
    {
        long long remainder = 1 % num;
        int length = 1;

        while (remainder != 0) 
        {
            remainder = (remainder * 10 + 1) % num;
            length++;
        }

        cout << length << '\n';
    }

    return 0;
}
