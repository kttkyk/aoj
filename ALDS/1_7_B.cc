#include <iostream>
#include <vector>
#include <string>


using namespace std;


using ll = long long;


class node {
    public:
        ll p, l, r;

        node();
};


node::node()
    : p(-1), l(-1), r(-1)
{
}


ll height(ll now, vector<node> &nodes, vector<ll> &H)
{
    if (nodes[now].l == -1 && nodes[now].r == -1) {
        H[now] = 0LL;
        return 0LL;
    }

    ll lh, rh;
    lh = rh = -1;
    if (nodes[now].l != -1)
        lh = height(nodes[now].l, nodes, H);
    if (nodes[now].r != -1)
        rh = height(nodes[now].r, nodes, H);
    H[now] = max(lh, rh) + 1;
    return H[now];
}


void depth(ll now, vector<node> &nodes, vector<ll> &D, ll d)
{
    D[now] = d;
    if (nodes[now].l != -1) {
        depth(nodes[now].l, nodes, D, d + 1);
    }
    if (nodes[now].r != -1) {
        depth(nodes[now].r, nodes, D, d + 1);
    }
}


string node_type(ll now, vector<node> &nodes)
{
    if (nodes[now].p == -1)
        return string("root");
    else if (nodes[now].l == -1 && nodes[now].r == -1)
        return string("leaf");
    else
        return string("internal node");
}


int main()
{
    ll n;
    cin >> n;
    vector<node> nodes(n);
    for (ll i = 0; i < n; i++) {
        ll id, left, right;
        cin >> id >> left >> right;
        nodes[id].l = left;
        nodes[id].r = right;
        nodes[left].p = id;
        nodes[right].p = id;
    }

    ll r;
    for (ll i = 0; i < n; i++) {
        if (nodes[i].p == -1) {
            r = i;
            break;
        }
    }

    vector<ll> H(n);
    vector<ll> D(n);

    height(r, nodes, H);
    depth(r, nodes, D, 0);

    for (ll i = 0; i < n; i++) {
        ll sib;
        if (r == i)
            sib = -1;
        else
            sib = nodes[nodes[i].p].l == i ? nodes[nodes[i].p].r : nodes[nodes[i].p].l;
        ll deg = 0;
        deg += nodes[i].l == -1 ? 0 : 1;
        deg += nodes[i].r == -1 ? 0 : 1;

        cout << "node " << i << ": parent = " << nodes[i].p << ", sibling = " << sib;
        cout << ", degree = " << deg << ", depth = " << D[i] << ", height = " << H[i] << ", " << node_type(i, nodes) << endl;
    }
}
