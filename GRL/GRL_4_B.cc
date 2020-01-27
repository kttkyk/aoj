#include <iostream>
#include <vector>
#include <queue>


using namespace std;


static const int MAX = 10000;


vector<int> graph[MAX];
vector<int> sorted;
vector<int> in_edges(MAX, 0);
vector<bool> discovered(MAX, false);
queue<int> visiting;
int V, E;


void bfs(int start)
{
    visiting.push(start);
    discovered[start] = true;

    while (!visiting.empty()) {
        int now = visiting.front();
        visiting.pop();

        sorted.push_back(now);

        for (vector<int>::iterator it = graph[now].begin(); it != graph[now].end(); ++it) {
            in_edges[*it]--;
            if (!discovered[*it] && in_edges[*it] == 0) {
                visiting.push(*it);
                discovered[*it] = true;
            }
        }
    }
}


int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        in_edges[t]++;
    }

    for (int i = 0; i < V; i++)
        if (!discovered[i] && in_edges[i] == 0)
            bfs(i);

    for (vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
