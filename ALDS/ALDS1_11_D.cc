#include <iostream>
#include <stack>
#include <vector>

using namespace std;


vector<int> vertexes[100000];
stack<int> visiting;
bool discovered[100000];
int belong[100000];
int subgraph_id = 0;


void dfs(int v)
{
    visiting.push(v);
    discovered[v] = true;
    belong[v] = ++subgraph_id;

    while (!visiting.empty()) {
        int now = visiting.top();
        visiting.pop();


        for (vector<int>::iterator it = vertexes[now].begin(); it != vertexes[now].end(); it++) {
            if (!discovered[*it]) {
                discovered[*it] = true;
                belong[*it] = subgraph_id;
                visiting.push(*it);
            }
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vertexes[x].push_back(y);
        vertexes[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        if (!discovered[i])
            dfs(i);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (belong[x] == belong[y])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
