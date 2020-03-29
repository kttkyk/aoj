#include <iostream>
#include <climits>


using namespace std;


using ll = long long;


int main() {
    ll coins[20];
    ll dp[20][50001] = {{ }};

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        cin >> coins[i];
    }

    for (ll i = 0; i < 50001; i++)
        dp[0][i] = i;

    for (ll i = 1; i < m; i++) {
        for (ll j = 1; j < n + 1; j++) {
            dp[i][j] = min(dp[i - 1][j], j - coins[i] >= 0 ? dp[i][j - coins[i]] + 1 : LONG_LONG_MAX);
        }
    }

    cout << dp[m - 1][n] << endl;
}
