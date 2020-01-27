#include <iostream>
#include <queue>

#define MAX 100

using namespace std;


queue<int> visiting;

int adj[MAX + 1][MAX + 1];
int d[MAX + 1];
int n, tt;
bool discovered[MAX + 1];


void bfs(int v)
{
    visiting.push(v);
    discovered[v] = true;
    d[v] = 0;

    while (!visiting.empty()) {
        int i;
        int now = visiting.front();

        visiting.pop();

        for (i = 1; i <= n; i++) {
            if (adj[now][i] && !discovered[i]) {
                visiting.push(i);
                discovered[i] = true;
                d[i] = d[now] + 1;
            }
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 1; i<= n; i++) {
        discovered[i] = false;
        d[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[id][v] = true;
        }

    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        cout << d[i] << endl;
    }

    return 0;
}
