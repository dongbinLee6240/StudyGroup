#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; i++) 
        cin >> num[i];
    cin >> X;

    sort(num.begin(), num.end());

    int l = 0, r = N - 1, cnt = 0;

    while (l < r) 
    {
        int sum = num[l] + num[r];
        if (sum == X) 
        {
            cnt++;
            l++; 
            r--; // 같은 쌍을 중복 세지 않도록 양쪽 이동
        }
        else if (sum < X) l++;
        else r--;
    }

    cout << cnt << "\n";
    return 0;
}
