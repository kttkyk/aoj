#include <iostream>
#include <cstdlib>


using namespace std;


struct node {
    long k;
    node *l, *r, *p;
};


int top = 0;
node nodes[500001];
node *t, *z;

void insert(long k)
{
    node *f = &nodes[top++];
    f->k = k;

    node *tmp = t, *p = z;
    while(tmp != z) {
        p = tmp;
        if (k <= tmp->k) {
            tmp = tmp->l;
        } else {
            tmp = tmp->r;
        }
    }

    f->p = p;
    if (p == z) {
        t = f;
    } else if (k <= p->k) {
        p->l = f;
    } else {
        p->r = f;
    }
}


void inorder(node *x)
{
    if (x->l != z)
        inorder(x->l);
    cout << " " << x->k;
    if (x->r != z)
        inorder(x->r);
}


void preorder(node *x)
{
    cout << " " << x->k;
    if (x->l != z)
        preorder(x->l);
    if (x->r != z)
        preorder(x->r);
}


void print()
{
    inorder(t);
    cout << endl;
    preorder(t);
    cout << endl;
}


node *find(long k)
{
    node *tmp = t;
    while (tmp != z && tmp->k != k) {
        if (k <= tmp->k)
            tmp = tmp->l;
        else
            tmp = tmp->r;
    }

    return tmp;
}


node *get_next(node *rt)
{
    node *tmp = rt->r;
    while (tmp->l != z)
        tmp = tmp->l;

    return tmp;
}


void delete_node(long k)
{
    node *target = find(k);
    if (target->l == z && target->r == z) {
        if (k <= target->p->k)
            target->p->l = z;
        else
            target->p->r = z;
        return;
    }

    if (target->l == z && target->r != z) {
        if (k <= target->p->k)
            target->p->l = target->r;
        else
            target->p->r = target->r;
        target->r->p = target->p;
        return;
    }

    if (target->l != z && target->r == z) {
        if (k <= target->p->k)
            target->p->l = target->l;
        else
            target->p->r = target->l;
        target->l->p = target->p;
        return;
    }

    node *next = get_next(target);
    long del_k = next->k;
    delete_node(del_k);
    target->k = del_k;
}


int main()
{
    int n;
    cin >> n;

    z= &nodes[n];
    z->p = z;
    z->l = z;
    z->r = z;

    t = z;

    for (int i = 0; i < n; i++) {
        nodes[i].p = z;
        nodes[i].l = z;
        nodes[i].r = z;
    }

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'i') {
            long k;
            cin >> k;
            insert(k);
        } else if (cmd[0] == 'p') {
            print();
        } else if (cmd[0] == 'f') {
            long k;
            cin >> k;
            if (find(k) == z)
                cout << "no" << endl;
            else
                cout << "yes" << endl;
        } else if (cmd[0] == 'd') {
            long k;
            cin >> k;
            delete_node(k);
        }
    }
}
