#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>


using namespace std;


class Node {
    public:
        int location;
        int p, l, r;
        Node() {}
};


class Point {
    public:
        int id, x, y;

        Point() {}
        Point(int id, int x, int y): id(id), x(x), y(y) {}

        bool operator <(const Point &p) const {
            return id < p.id;
        }

        void print() {
            printf("%d\n", id);
        }
};


static const int MAX = 1000000;
static const int NIL = -1;


int N;
Point P[MAX];
Node T[MAX];
int np = 0;


bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }


int makeKDTree(int l, int r, int d)
{
    if (!(l < r))
        return NIL;

    int mid = (l + r) / 2;
    int t = np++;

    if (d % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }

    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, d + 1);
    T[t].r = makeKDTree(mid + 1, r, d + 1);

    return t;
}


void find(int v, int sx, int tx, int sy, int ty, int d, vector<Point> &ans)
{
    Point p = P[T[v].location];
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if (sx <= p.x && p.x <= tx && sy <= p.y && p.y <= ty)
        ans.push_back(p);

    if (d % 2 == 0) {
        if (T[v].l != NIL && sx <= x)
            find(T[v].l, sx, tx, sy, ty, d + 1, ans);
        if (T[v].r != NIL && x <= tx)
            find(T[v].r, sx, tx, sy, ty, d + 1, ans);
    } else {
        if (T[v].l != NIL && sy <= y)
            find(T[v].l, sx, tx, sy, ty, d + 1, ans);
        if (T[v].r != NIL && y <= ty)
            find(T[v].r, sx, tx, sy, ty, d + 1, ans);
    }
}


int main()
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }

    int root = makeKDTree(0, n, 0);

    int q;
    int sx, sy, tx, ty;
    vector<Point> ans;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++)
            ans[j].print();
        printf("\n");
    }

    return 0;
}
