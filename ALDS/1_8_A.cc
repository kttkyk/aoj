#include <iostream>
#include <vector>
#include <string>


using namespace std;


using ll = long long;


class node {
    public:
        node();
        ll k;
        node *l, *r, *p;
};


node::node()
    : l{nullptr}, r{nullptr}, p{nullptr}
{
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

    if (root == nullptr)
        root = n;
    else if (parent->k <= n->k)
        parent->r = n;
    else
        parent->l = n;
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
        }
    }
}
