#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>


using namespace std;


using ll = long long;


static const ll INF = (1LL << 32);


ll V, E;
vector< vector<ll> > adj(100, vector<ll>(100, INF));


int main()
{
    cin >> V >> E;

    for (ll i = 0; i < E; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        adj[x][y] = c;
    }

    for (ll i = 0; i < V; i++) {
        adj[i][i] = 0;
    }


    for (ll k = 0; k < V; k++) {
        for (ll i = 0; i < V; i++) {
            for (ll j = 0; j < V; j++) {
                if (adj[i][k] == INF || adj[k][j] == INF)
                    continue;

                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (ll i = 0; i < V; i++) {
        if (adj[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            if (adj[i][j] == INF)
                cout << "INF";
            else
                cout << adj[i][j];
            if (j != V - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
