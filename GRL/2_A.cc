#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


using ll = long long;


class edge {
    public:
        ll src, dst, cost;
        edge(ll src, ll dst, ll cost)
            : src(src), dst(dst), cost(cost)
        {
        }

        bool operator < (const edge &e)
        {
            return cost < e.cost;
        }
};


class disjoint_set {
    vector<long long> parent, rank;

    public:
        disjoint_set();
        disjoint_set(long long size);

        void make_set(long long x);
        long long find_set(long long x);
        void unite(long long x, long long y);
        void resize(long long size);
};


disjoint_set::disjoint_set(long long size)
{
    parent.resize(size);
    rank.resize(size);

    for (long long i = 0; i < size; i++) {
        make_set(i);
    }
}


disjoint_set::disjoint_set()
    : disjoint_set(0)
{
}


void disjoint_set::resize(long long size)
{
    parent.resize(size);
    rank.resize(size);

    for (long long i = 0; i < size; i++) {
        make_set(i);
    }
}


void disjoint_set::make_set(long long x)
{
    parent[x] = x;
    rank[x] = 0;
}


long long disjoint_set::find_set(long long x)
{
    if (x != parent[x]) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}


void disjoint_set::unite(long long x, long long y)
{
    long long rx, ry;
    rx = find_set(x);
    ry = find_set(y);
    if (rank[rx] == rank[ry]) {
        parent[rx] = ry;
        // when the rank (height) of the trees are the same
        // uniting trees will increase the rank.
        rank[ry]++;
    } else if (rank[rx] < rank[ry]) {
        // uniting a shorter tree under a higher tree
        // won't change the rank (height) of the united tree.
        parent[rx] = ry;
    } else {
        parent[ry] = rx;
    }
}


void kruskal(vector<edge> &edges, disjoint_set &trees, vector<edge> &mst)
{
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        if (trees.find_set(e.src) == trees.find_set(e.dst))
            continue;
        trees.unite(e.src, e.dst);
        mst.push_back(e);
    }
}


int main()
{
    ll V, E;
    vector<edge> edges;
    cin >> V >> E;
    for (ll i = 0; i < E; i++) {
        ll s, t, w;
        cin >> s >> t >> w;
        edges.push_back(edge(s, t, w));
    }

    disjoint_set trees(V);
    vector<edge> mst;
    kruskal(edges, trees, mst);

    ll acc = 0;
    for (auto e : mst)
        acc += e.cost;
    cout << acc << endl;
}
