#include <iostream>

using namespace std;


struct node {
    int p, l, r;
};
node nodes[100000];


void preorder(int id)
{
    cout << " " << id;
    if (nodes[id].l >= 0)
        preorder(nodes[id].l);
    if (nodes[id].r >= 0)
        preorder(nodes[id].r);
}


void inorder(int id)
{
    if (nodes[id].l >= 0)
        inorder(nodes[id].l);
    cout << " " << id;
    if (nodes[id].r >= 0)
        inorder(nodes[id].r);
}


void postorder(int id)
{
    if (nodes[id].l >= 0)
        postorder(nodes[id].l);
    if (nodes[id].r >= 0)
        postorder(nodes[id].r);
    cout << " " << id;
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        nodes[i].p = -1;

    for (int i = 0; i < n; i++) {
        int id;
        int l, r;
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
    for (int i = 0; i < n; i++)
        if (nodes[i].p == -1) {
            root = i;
            break;
        }

    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;
}
