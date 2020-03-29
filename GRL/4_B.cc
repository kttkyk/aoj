#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;


using ll = long long;


vector<vector<ll>> graph;
vector<ll> out;
// list<ll> out;
vector<bool> discovered;
vector<ll> indeg;
ll V, E;

/*
void bfs(ll start)
{
    queue<ll> q;
    q.push(start);
    discovered[start] = true;

    while (!q.empty()) {
        ll now = q.front();
        q.pop();

        out.push_back(now);

        for (auto e : graph[now]) {
            indeg[e]--;
            if (indeg[e] == 0 && !discovered[e]) {
                discovered[e] = true;
                q.push(e);
            }
        }
    }
}


void topological_sort_bfs()
{
    for (ll i = 0; i < V; i++) {
        if (indeg[i] == 0 && !discovered[i]) {
            bfs(i);
        }
    }
}
*/


void dfs(ll now)
{
    discovered[now] = true;
    for (auto e : graph[now]) {
        if (!discovered[e])
            dfs(e);
    }
    out.push_back(now);
}


void topological_sort_dfs()
{
    // for (ll i = 0; i < V; i++) {
    for (ll i = V - 1; i >= 0; i--) {
        if (!discovered[i])
            dfs(i);
    }
    reverse(out.begin(), out.end());
}


int main()
{

    cin >> V >> E;
    graph.resize(V);
    discovered.resize(V, false);
    indeg.resize(V, 0);

    for (ll i = 0; i < E; i++) {
        ll s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        indeg[t]++;
    }

    topological_sort_dfs();

    for (auto e : out)
        cout << e << endl;
}
