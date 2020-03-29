#include <iostream>
#include <vector>
#include <string>
#include <climits>


using namespace std;


using ll = long long;


class node {
    public:
        node();
        ll k;
        node *l, *r, *p;
        const void dump();
};


node::node()
    : l{nullptr}, r{nullptr}, p{nullptr}
{
}


const void node::dump()
{
    cout << this->p << ", " << this->l << ", " << this->r << endl;
}



node *root = nullptr;


void insert(node *n)
{
    node *parent, *now;
    now = root;
    while (now != nullptr) {
        parent = now;
        if (now->k <= n->k)
            now = now->r;
        else
            now = now->l;
    }

    if (root == nullptr) {
        root = n;
        root->p = root;
    }
    else if (parent->k <= n->k) {
        parent->r = n;
    } else {
        parent->l = n;
    }
    n->p = parent;
}


node *get_next(node *n)
{
    node *now = n->r;
    while (now->l != nullptr)
        now = now->l;
    return now;
}


node *find(ll k)
{
    node *now = root;
    while (now != nullptr && now->k != k) {
        if (now->k <= k)
            now = now->r;
        else
            now = now->l;
    }

    return now;
}


void delete_node(ll k)
{
    node *target = find(k);
    node *new_child = target;

    if (target->r == nullptr) {
        new_child = target->l;
    } else if (target->r->l == nullptr) {
        new_child = target->r;
        new_child->l = target->l;
    } else {
        // get the node with the smallest value
        // from the right partial tree
        new_child = get_next(target);
        new_child->p->l = new_child->r;
        new_child->l = target->l;
        new_child->r = target->r;
    }

    if (target->p->r == target) {
        target->p->r = new_child;
    } else {
        target->p->l = new_child;
    }
    if (new_child) {
        new_child->p = target->p;
    }
    delete target;
}


void _delete_node(ll k)
{
    node *target = find(k);
    node *new_child = target;
    node *del_target;

    if (target->l != nullptr && target->r != nullptr) {
        del_target = get_next(target);
    } else {
        del_target = target;
    }

    // del_target should have only 1 child at max
    if (del_target->l != nullptr) {
        new_child = del_target->l;
    } else {
        new_child = del_target->r;
    }

    if (new_child != nullptr) {
        new_child->p = del_target->p;
    }

    if (del_target->p->l == del_target) {
        del_target->p->l = new_child;
    } else {
        del_target->p->r = new_child;
    }

    // if (target->l != nullptr && target->r != nullptr) {
    if (del_target != target) {
        target->k = del_target->k;
    }
    delete del_target;
}


void inorder(node *now, vector<ll> &log)
{
    if (now->l != nullptr)
        inorder(now->l, log);

    log.push_back(now->k);

    if (now->r != nullptr)
        inorder(now->r, log);
}


void preorder(node *now, vector<ll> &log)
{
    log.push_back(now->k);

    if (now->l != nullptr)
        preorder(now->l, log);

    if (now->r != nullptr)
        preorder(now->r, log);
}


void print_log(vector<ll> &log)
{
    for (auto it = log.begin(); it != log.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}


int main()
{
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++) {
        vector<ll> log;
        vector<node *> nodes;
        string cmd;
        node *n;
        ll k;

        cin >> cmd;
        switch(cmd[0]) {
            case 'i':
                cin >> k;
                n = new node;
                n->k = k;
                insert(n);
                break;
            case 'p':
                inorder(root, log);
                print_log(log);
                log.clear();

                preorder(root, log);
                print_log(log);
                log.clear();
                break;
            case 'f':
                cin >> k;
                if (find(k)) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
                break;
            case 'd':
                cin >> k;
                _delete_node(k);
        }
    }
}
