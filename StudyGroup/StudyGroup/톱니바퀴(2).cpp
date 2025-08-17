#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, K;
int cnt = 0;

// 특정 비트 가져오기
int getbit(int gear, int num) {
    return (gear >> num) & 1;
}

// 반시계 회전
int leftrot(int gear) {
    return ((gear << 1) | ((gear >> 7) & 1)) & 0xFF;
}

// 시계 회전
int rightrot(int gear) {
    return ((gear >> 1) | ((gear & 1) << 7)) & 0xFF;
}

void solve(vector<int>& gears, int num, int b)
{
    vector<int> dir(T, 0);
    dir[num] = b;

    // 왼쪽 방향 결정
    for (int i = num - 1; i >= 0; i--)
    {
        if (getbit(gears[i], 2) == getbit(gears[i + 1], 6))
            break;
        dir[i] = -dir[i + 1];
    }
    // 오른쪽 방향 결정
    for (int i = num + 1; i < T; i++)
    {
        if (getbit(gears[i - 1], 2) == getbit(gears[i], 6))
            break;
        dir[i] = -dir[i - 1];
    }

    // 방향에 맞게 회전
    for (int i = 0; i < T; i++)
    {
        if (dir[i] == 1)
            gears[i] = rightrot(gears[i]); // 시계
        else if (dir[i] == -1)
            gears[i] = leftrot(gears[i]); // 반시계
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    vector<int> gears(T);

    for (int i = 0; i < T; i++)
    {
        string line;
        cin >> line;
        int mask = 0;
        for (int j = 0; j < 8; j++)
        {
            if (line[j] == '1')
                mask |= (1 << j); // j 그대로 저장 (0번이 12시 방향)
        }
        gears[i] = mask;
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num, dir;
        cin >> num >> dir;
        solve(gears, num - 1, dir); // 0-index 변환
    }

    for (int i = 0; i < T; i++)
    {
        if (getbit(gears[i], 0) == 1) cnt++;
    }
    cout << cnt;
}
