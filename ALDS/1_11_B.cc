#include <iostream>


using namespace std;


using ll = long long;


const ll MAX = 100;

bool adj[MAX + 1][MAX + 1] = {};
bool visited[MAX + 1] = {};
ll d[MAX + 1], f[MAX + 1];
ll n;
ll t = 1;


void dfs(ll now)
{
    visited[now] = true;
    d[now] = t++;
    for (ll i = 1; i <= n; i++) {
        if (!adj[now][i])
            continue;
        if (visited[i])
            continue;

        dfs(i);
    }
    f[now] = t++;
}


int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll v;
            cin >> v;
            adj[u][v] = true;
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }

    for (ll i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}
