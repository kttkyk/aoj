#include <iostream>
#include <cstdlib>

using namespace std;


struct node {
    int id;
    node *next;
};


node hdrs[101];
int adj[101][101];


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        hdrs[i].next = &hdrs[i];
        hdrs[i].id = i;
    }

    for (int i = 1; i <= n; i++) {
        int k;
        int id;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;

            node *t = (node *)malloc(sizeof(node));
            t->id = v;
            t->next = hdrs[id].next;
            hdrs[id].next = t;
        }
    }

    for (int i = 1; i <= n; i++) {
        node *t = &hdrs[i];
        while (t->next != &hdrs[i]) {
            t = t->next;
            adj[i][t->id] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << adj[i][n] << endl;
    }

    return 0;
}
