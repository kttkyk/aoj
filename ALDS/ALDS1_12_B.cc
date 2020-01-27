#include <iostream>
#include <climits>

#define MAX 100

using namespace std;


int adj[MAX][MAX];
int p[MAX];
int d[MAX];
int n;
bool in_tree[MAX];


void dijkstra()
{
    for (int i = 0; i < n; i++) {
        p[i] = -1;
        d[i] = INT_MAX;
        in_tree[i] = false;
    }

    d[0] = 0;
    while (true) {
        int min_cos = INT_MAX;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!in_tree[i] && min_cos > d[i]) {
                u = i;
                min_cos = d[i];
            }
        }


        if (min_cos == INT_MAX)
            break;

        in_tree[u] = true;

        for (int i = 0; i < n; i++) {
            if (!in_tree[i] && adj[u][i] >= 0 && min_cos + adj[u][i] < d[i]) {
                d[i] = min_cos + adj[u][i];
                p[i] = u;
            }
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = -1;

    for (int i = 0; i < n; i++) {
        int k, u;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            adj[u][v] = c;
        }
    }


    dijkstra();

    for (int i = 0; i < n - 1; i++) {
        cout << i << " " << d[i] << endl;
    }
    cout << n - 1<< " " << d[n - 1] << endl;

    return 0;
}
