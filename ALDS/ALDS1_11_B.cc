#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;


stack<int> visiting;

#define MAX 100
bool adj[MAX + 2][MAX + 2];
int d[MAX + 1], f[MAX + 1];
bool discovered[MAX + 1];
int tt, n;


void dfs(int v)
{
    visiting.push(v);
    discovered[v] = true;
    d[v] = ++tt;

    while (!visiting.empty()) {
        int now = visiting.top();
        int i;
        for (i = 1; i <= n; i++) {
            if (adj[now][i] && !discovered[i])
                break;
        }

        if (!discovered[i] && i <= n) {
            d[i] = ++tt;
            visiting.push(i);
            discovered[i] = true;
        } else {
            f[now] = ++tt;
            visiting.pop();
        }
    }
}


void dfs_rec(int v)
{
    discovered[v] = true;
    d[v] = ++tt;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !discovered[i])
            dfs_rec(i);
    }
    f[v] = ++tt;
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[id][v] = true;
        }

        discovered[i] = false;
    }

    for (int i = 1; i <= n; i++)
        if (!discovered[i])
            dfs_rec(i);


    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        cout << d[i] << " ";
        cout << f[i] << endl;
    }

    return 0;
}
