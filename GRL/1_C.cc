#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;


using ll = long long;


const ll MAX = 100;


vector<vector<pair<ll, ll>>> graph;


int main()
{
    ll V, E;
    cin >> V >> E;
    graph.resize(V);

    for (ll i = 0; i < E; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(make_pair(d, t));
    }

    ll dp[MAX + 1][MAX + 1] = {};
    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            dp[i][j] = i == j ? 0 : LONG_LONG_MAX;
        }
    }

    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            for (auto e : graph[i]) {
                if (e.second == j) {
                    dp[i][j] = e.first;
                    break;
                }
            }
        }
    }

    for (ll k = 0; k < V; k++) {
        for (ll i = 0; i < V; i++) {
            if (dp[i][k] == LONG_LONG_MAX)
                continue;
            for (ll j = 0; j < V; j++) {
                if (dp[k][j] == LONG_LONG_MAX)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (ll i = 0; i < V; i++) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            if (dp[i][j] != LONG_LONG_MAX) {
                cout << dp[i][j];
            } else {
                cout << "INF";
            }
            if (j != V - 1)
                cout << " ";
        }
        cout << endl;
    }
}
