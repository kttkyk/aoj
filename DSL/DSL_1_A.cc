#include <iostream>
#include <vector>


using namespace std;


#define MAX 10000


int parent[MAX];
int rank[MAX];


int find(int x)
{
    int now = x;
    vector<int> children;
    while (parent[now] != now) {
        children.push_back(now);
        now = parent[now];
    }

    // path compression
    for (vector<int>::iterator it = children.begin(); it != children.end(); ++it)
        parent[*it] = now;

    return now;
}


void unite(int x, int y)
{
    int rx = find(x);
    int ry = find(y);

    if (rank[rx] > rank[ry]) {
        parent[ry] = rx;
    } else if (rank[rx] < rank[ry]) {
        parent[rx] = ry;
    } else {
        parent[ry] = rx;
        rank[rx]++;
    }
}


bool same(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    return rx == ry;
}


int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < q; i++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        switch (cmd) {
            case 0:
                unite(x, y);
                break;
            case 1:
                if (same(x, y))
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
                break;
        }
    }
}
