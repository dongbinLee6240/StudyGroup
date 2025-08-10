#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 끝나는 시간 기준 정렬
bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 끝나는 시간 기준 정렬
    sort(meetings.begin(), meetings.end(), compare);

    int count = 0;
    int end_time = 0;

    for (int i = 0; i < N; ++i) {
        if (meetings[i].first >= end_time) {
            ++count;
            end_time = meetings[i].second;
        }
    }

    cout << count << '\n';
    return 0;
}
