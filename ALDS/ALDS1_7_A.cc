#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


struct node {
    int num_ch;
    int parent, lc, rs;
    int depth;
};


node nodes[100000];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        nodes[i].num_ch = 0;
        nodes[i].parent = -1;
        nodes[i].lc = nodes[i].rs = -1;
        nodes[i].depth = 0;
    }

    for (int i = 0 ; i < n; i++) {
        int id;
        int k, ls;
        cin >> id >> k;
        nodes[id].num_ch = k;

        if (k) {
            cin >> nodes[id].lc;
            ls = nodes[id].lc;
            nodes[nodes[id].lc].parent = id;
        }

        for (int j = 1; j < k; j++) {
            cin >> nodes[ls].rs;
            ls = nodes[ls].rs;
            nodes[ls].parent = id;
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp = i;
        while (nodes[tmp].parent != -1) {
            nodes[i].depth++;
            tmp = nodes[tmp].parent;
        }
    }

    for (int i = 0; i < n; i++) {
        node tmp = nodes[i];
        printf("node %d: parent = %d, depth = %d, ", i, tmp.parent, tmp.depth);
        if (tmp.parent == -1)
            printf("root, ");
        else if(tmp.num_ch == 0)
            printf("leaf, ");
        else
            printf("internal node, ");
        printf("[");

        for (int cid = tmp.lc; cid != -1; cid = nodes[cid].rs) {
            printf("%d", cid);
            if (nodes[cid].rs != -1)
                printf(", ");
        }
        printf("]\n");
    }
}


/*
struct node {
    long id;
    long parent_id;
    long num_children;
    long *children;
    long d;
};


node nodes[100000];
int main()
{
    long n;
    scanf("%ld", &n);

    for (long i = 0; i < n; i++) {
        nodes[i].d = 0;
        nodes[i].parent_id = -1;
    }

    for (long i = 0; i < n; i++) {
        long id;
        scanf("%ld", &id);
        nodes[id].id = id;
        scanf("%ld", &nodes[id].num_children);

        nodes[id].children = (long *)malloc(sizeof(node) * nodes[id].num_children);

        for (long j = 0; j < nodes[id].num_children; j++) {
            long cid;
            scanf("%ld", &cid);
            nodes[id].children[j] = cid;
            nodes[cid].parent_id = id;
        }
    }


    for (long i = 0; i < n; i++) {
        node tmp = nodes[i];
        long id = tmp.id;
        while(tmp.parent_id != -1) {
            nodes[id].d++;
            tmp = nodes[tmp.parent_id];
        }
    }

    for (long i = 0; i < n; i++) {
        node tmp = nodes[i];
        printf("node %ld: parent = %ld, depth = %ld, ", tmp.id, tmp.parent_id, tmp.d);
        if (tmp.parent_id == -1)
            printf("root, ");
        else if(tmp.num_children == 0)
            printf("leaf, ");
        else
            printf("internal node, ");
        printf("[");
        for (long j = 0; j < tmp.num_children; j++) {
            printf("%ld", tmp.children[j]);
            if (j != tmp.num_children - 1)
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}
*/
