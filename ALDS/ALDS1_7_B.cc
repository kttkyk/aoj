#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


struct node {
    int p, l, r;
    int d, h;
};
node nodes[100000];


void reg_depth(int id, int d)
{
    nodes[id].d = d;
    if (nodes[id].l >= 0)
        reg_depth(nodes[id].l, d + 1);
    if (nodes[id].r >= 0)
        reg_depth(nodes[id].r, d + 1);
}


int reg_height(int id)
{
    if (nodes[id].l == -1 && nodes[id].r == -1)
        return 0;

    int h, lh, rh;
    if (nodes[id].l >= 0)
        lh = reg_height(nodes[id].l) + 1;
    else
        lh = 0;
    if (nodes[id].r >= 0)
        rh = reg_height(nodes[id].r) + 1;
    else
        rh = 0;

    h = max(lh, rh);
    nodes[id].h = h;
    return h;
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        nodes[i].p = -1;

    for (int i = 0; i < n; i++) {
        int id, l, r;
        cin >> id;
        cin >> l >> r;
        nodes[id].l = l;
        nodes[id].r = r;

        if (l >= 0)
            nodes[l].p = id;
        if (r >= 0)
            nodes[r].p = id;
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (nodes[i].p == -1) {
            root = i;
            break;
        }
    }

    reg_depth(root, 0);
    reg_height(root);

    for (int i = 0; i < n; i++) {
        int s = -1;
        if (nodes[i].p != -1) {
            int l, r;
            l = nodes[nodes[i].p].l;
            r = nodes[nodes[i].p].r;
            s = l != i ? l : r;
        }
        int deg = 0;
        if (nodes[i].l != -1)
            deg++;
        if (nodes[i].r != -1)
            deg++;

        string type;
        if (nodes[i].p == -1)
            type = "root";
        else if (nodes[i].l == -1 && nodes[i].r == -1)
            type = "leaf";
        else
            type = "internal node";

        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
                i, nodes[i].p, s, deg, nodes[i].d, nodes[i].h);
        cout << type << endl;
    }

    return 0;
}
