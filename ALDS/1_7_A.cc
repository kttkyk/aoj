#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

class Node {
    public:
        Node();
        ll p, l, r;
};


Node::Node()
    : p(-1), l(-1), r(-1)
{
}


void depth(vector<Node> &nodes, vector<ll> &D, ll id, ll d)
{
    D[id] = d;
    if (nodes[id].l != -1)
        depth(nodes, D, nodes[id].l, d + 1);
    if (nodes[id].r != -1)
        depth(nodes, D, nodes[id].r, d);
}


string node_type(vector<Node> &nodes, ll id)
{
    if (nodes[id].p == -1)
        return string("root");
    else if (nodes[id].l == -1)
        return string("leaf");
    else
        return string("internal node");
}


int main()
{
    ll n;
    cin >> n;
    vector<Node> nodes(n);

    for (ll i = 0; i < n; i++) {
        ll id, k;
        cin >> id >> k;
        for (ll j = 0; j < k; j++) {
            ll c, sib;
            cin >> c;
            if (j == 0) {
                nodes[id].l = c;
            } else {
                nodes[sib].r = c;
            }
            nodes[c].p = id;
            sib = c;
        }
    }

    ll root;
    for (ll i = 0; i < n; i++) {
        if (nodes[i].p == -1) {
            root = i;
            break;
        }
    }

    vector<ll> D(n);
    depth(nodes, D, root, 0);

    for (ll i = 0; i < n; i++) {
        cout << "node " << i << ": parent = " << nodes[i].p << ", depth = " << D[i] << ", " << node_type(nodes, i) << ", ";
        cout << "[";

        ll c = nodes[i].l;
        while (c != -1) {
            cout << c;
            if (nodes[c].r != -1)
                cout << ", ";
            c = nodes[c].r;
        }
        cout << "]";

        cout << endl;
    }
}
