#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int K;

void recur(const vector<int>& t, int level, vector<string>& ans)
{
    if (t.empty()) return;

    int mid = t.size() / 2;

    vector<int> left(t.begin(), t.begin() + mid);
    vector<int> right(t.begin() + mid + 1, t.end());

    ans[level] += to_string(t[mid]) + " ";

    recur(left, level + 1, ans);
    recur(right, level + 1, ans);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> K;

    int total = pow(2, K) - 1;
    vector<int> tree(total);

    for (int i = 0; i < total; i++)
    {
        cin >> tree[i];
    }

    vector<string> answer(K); // 각 레벨의 노드 값 저장
    recur(tree, 0, answer);

    for (int i = 0; i < K; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}
