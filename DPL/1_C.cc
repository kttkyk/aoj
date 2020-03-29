#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


using ll = long long;


int main()
{
    ll N, W;
    cin >> N >> W;

    ll dp[N + 1][W + 1];
    ll weight[N + 1], value[N + 1];
    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i <= N; i++) {
        cin >> value[i] >> weight[i];
    }

    dp[1][weight[1]] = value[1];
    for (ll i = 1; i <= N; i++) {
        for (ll w = 1; w <= W; w++) {
            dp[i][w] = max({
                            dp[i - 1][w],
                            w - weight[i] >= 0 ? dp[i - 1][w - weight[i]] + value[i] : 0,
                            w - weight[i] >= 0 ? dp[i][w - weight[i]] + value[i] : 0
                            });
        }
    }

    cout << dp[N][W] << endl;
}
