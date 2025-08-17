#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L; // ¿õµ¢ÀÌ °³¼ö, ³ÎºþÁö ±æÀÌ
    cin >> n >> L;

    vector<pair<int, int>> pools(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> pools[i].first >> pools[i].second;
    }

    sort(pools.begin(), pools.end());

    int ans = 0, cover = 0;

    for (auto [l, r] : pools) 
    {
        if (cover < l) 
            cover = l; // ¾È µ¤¿´À¸¸é µ¤±â ½ÃÀÛ
        while (cover < r) 
        {
            cover += L; // ³ÎºþÁö ÇÏ³ª Ãß°¡
            ans++;
        }
    }
    cout << ans;

    return 0;
}
