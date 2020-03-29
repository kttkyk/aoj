#include <iostream>
#include <vector>


using namespace std;


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



int main()
{
    disjoint_set ds;

    long long n, q;
    cin >> n >> q;

    ds.resize(n + 1);

    for (long long i = 0; i < q; i++) {
        long long com, x, y;
        cin >> com >> x >> y;

        switch(com) {
            case 0:
                ds.unite(x, y);
                break;
            case 1:
                if (ds.find_set(x) == ds.find_set(y)) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
                break;
        }
    }
}
