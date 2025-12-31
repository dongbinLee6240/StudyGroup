#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>
#include<cstring>
using namespace std;

struct Rot 
{
    int r, c, s;
};

int N, M, K;
int board[51][51];
int temp[51][51];

vector<Rot> rot;

void rotate_once(int r, int c, int s) 
{
    for (int layer = 1; layer <= s; layer++) 
    {
        int top = r - layer; 
        int left = c - layer;
        int bottom = r + layer;
        int right = c + layer;

        int prev = temp[top][left];
        // 왼쪽
        for (int i = top; i < bottom; i++) 
        {
            temp[i][left] = temp[i + 1][left];
        }
        // 아래
        for (int j = left; j < right; j++) 
        {
            temp[bottom][j] = temp[bottom][j + 1];
        }
        // 오른쪽
        for (int i = bottom; i > top; i--)
        {
            temp[i][right] = temp[i - 1][right];
        }
        // 위
        for (int j = right; j > left + 1; j--) 
        {
            temp[top][j] = temp[top][j - 1];
        }
        temp[top][left + 1] = prev;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++) 
        {
            cin >> board[i][j];
        }
    }

    rot.resize(K);
    for (int i = 0; i < K; i++) 
    {
        cin >> rot[i].r >> rot[i].c >> rot[i].s;
    }

    vector<int> perm(K);
    std::iota(perm.begin(), perm.end(), 0); // 0..K-1

    int ans = INT_MAX;

    do 
    {
        // 배열 복사
        memcpy(temp, board, sizeof(board));
        // 순열대로 회전 수행
        for (int idx : perm) 
        {
            rotate_once(rot[idx].r, rot[idx].c, rot[idx].s);
        }
        // 최소 행합 계산
        for (int i = 1; i <= N; i++) 
        {
            int sum = 0;
            for (int j = 1; j <= M; j++) 
                sum += temp[i][j];
            ans = min(ans, sum);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << "\n";
}
