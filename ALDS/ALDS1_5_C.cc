#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define RT3 1.7320508075


struct point {
    double x, y;
};


void print_point(point p)
{
    printf("%.08f %.08f\n", p.x, p.y);
}


void koch(point l, point r, int depth)
{
    if (depth == 0)
        return;

    double th = M_PI * 60.0 / 180.0;

    point new_l, new_r, middle;

    new_l.x = (2.0 * l.x + 1.0 * r.x) / 3.0;
    new_l.y = (2.0 * l.y + 1.0 * r.y) / 3.0;
    new_r.x = (1.0 * l.x + 2.0 * r.x) / 3.0;
    new_r.y = (1.0 * l.y + 2.0 * r.y) / 3.0;
    middle.x = (new_r.x - new_l.x) * cos(th) - (new_r.y - new_l.y) * sin(th) + new_l.x;
    middle.y = (new_r.x - new_l.x) * sin(th) + (new_r.y - new_l.y) * cos(th) + new_l.y;


    koch(l, new_l, depth - 1);

    print_point(new_l);
    koch(new_l, middle, depth - 1);

    print_point(middle);
    koch(middle, new_r, depth - 1);

    print_point(new_r);
    koch(new_r, r, depth - 1);
}


int main()
{
    int n;
    cin >> n;
    point l, r;

    l.x = 0;
    l.y = 0;
    r.x = 100;
    r.y = 0;

    print_point(l);
    koch(l, r, n);
    print_point(r);
}
