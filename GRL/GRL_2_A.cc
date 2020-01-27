#include <iostream>
#include <set>
#include <algorithm>
#include <vector>


using namespace std;


class DisjointSet {
    public:

        const int MAX = 100000;
        vector<int> parent;
        vector<int> rank;

        DisjointSet()
        {
            parent = vector<int>(MAX, 0);
            rank = vector<int>(MAX, 0);
        }


        void make_set(int x)
        {
            parent[x] = x;
            rank[x] = 0;
        }

        int find_set(int x)
        {
            int p = parent[x];
            while (parent[p] != p)
                p = parent[p];
            return p;
        }

        void unite(int x, int y)
        {
            int xr, yr;
            xr = find_set(x);
            yr = find_set(y);

            if (rank[xr] > rank[yr]) {
                parent[yr] = xr;
            } else if (rank[xr] < rank[yr]) {
                parent[xr] = yr;
            } else if (rank[xr] == rank[yr]) {
                parent[yr] = xr;
                rank[yr]++;
            }
        }
};


class Edge {
    public:

        int src, dst, cost;

        Edge(int src = 0, int dst = 0, int cost = 0)
            : src(src), dst(dst), cost(cost)
        { }

        bool operator <(const Edge &e) const {
            return cost < e.cost;
        }
};


int kruskal(vector<Edge> edges, int V)
{
    DisjointSet ds = DisjointSet();
    int total_cost = 0;

    for (int i = 0; i < V; i++) {
        ds.make_set(i);
    }

    sort(edges.begin(), edges.end());

    int c = 0;
    set<Edge> spanning_tree;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        if (ds.find_set((*it).src) != ds.find_set((*it).dst)) {
            ds.unite((*it).src, (*it).dst);
            total_cost += (*it).cost;
            spanning_tree.insert((*it));
        }
    }

    return total_cost;
}


int main()
{
    int V, E;
    vector<Edge> edges;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.push_back(Edge(s, t, w));
    }

    cout << kruskal(edges, V) << endl;

    return 0;
}
