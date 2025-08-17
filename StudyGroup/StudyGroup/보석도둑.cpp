#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Jewel 
{
    int m; // 무게
    int v; // 가격
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Jewel> jewels(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> jewels[i].m >> jewels[i].v;
    }

    vector<int> bags(K);
    for (int i = 0; i < K; i++) 
    {
        cin >> bags[i];
    }

    // 무게 기준으로 정렬
    sort(jewels.begin(), jewels.end(), [](auto& a, auto& b) 
        {
        return a.m < b.m;
        });
    sort(bags.begin(), bags.end());

    priority_queue<int> pq; // 가격 최대힙
    long long result = 0;
    int idx = 0;

    for (int i = 0; i < K; i++) 
    {
        // 현재 가방에 들어갈 수 있는 보석들을 모두 pq에 넣음
        while (idx < N && jewels[idx].m <= bags[i]) 
        {
            pq.push(jewels[idx].v);
            idx++;
        }

        // pq에서 가장 비싼 보석 꺼내기
        if (!pq.empty()) 
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << "\n";
}
