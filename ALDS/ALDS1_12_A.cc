#include <iostream>
#include <set>
#include <climits>


using namespace std;


#define MAX 100


set<int> spt; // spanning tree
int adj[MAX][MAX];
int tree_d[MAX]; // minimum distance to the tree
int p[MAX];
int n;

int prim()
{
    for (int i = 0; i < n; i++)
        tree_d[i] = INT_MAX;

    tree_d[0] = 0;
    while (spt.size() < (unsigned int)n) {
        int min_d = INT_MAX;
        int u = 0;
        for (int i = 0; i < n; i++) {
            if (spt.find(i) == spt.end() && min_d > tree_d[i]) {
                min_d = tree_d[i];
                u = i;
            }
        }

        spt.insert(u);
        for (int i = 0; i < n; i++) {
            if (spt.find(i) == spt.end() && adj[u][i] >= 0 && adj[u][i] < tree_d[i]) {
                tree_d[i] = adj[u][i];
                p[i] = u;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        if (adj[i][p[i]] >= 0)
            sum += adj[i][p[i]];
    return sum;
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }

    int res = prim();
    cout << res << endl;

    return 0;
}
