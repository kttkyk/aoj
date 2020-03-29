#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;


using ll = long long;


const ll MAX = 100;


vector<list<ll>> graph;
ll d[MAX + 1] = {};
ll n;
bool visited[MAX + 1] = {};

void bfs()
{
    queue<pair<ll, ll>> q;
    q.push(make_pair(1, 0));
    visited[1] = true;

    while (!q.empty()) {
        auto tmp = q.front(); q.pop();
        ll now = tmp.first; ll dis = tmp.second;

        d[now] = dis;

        for (auto e : graph[now]) {
            if (!visited[e]) {
                visited[e] = true;
                q.push(make_pair(e, dis + 1));
            }
        }
    }
}


int main()
{
    cin >> n;
    graph.resize(n + 1);
    for (ll i = 0; i < n; i++) {
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll v;
            cin >> v;
            graph[u].push_back(v);
        }
    }

    bfs();

    for (ll i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << " " << d[i] << endl;
        } else {
            cout << i << " " << -1 << endl;
        }
    }
}
