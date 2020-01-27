#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


#define MAX 1000000
#define INITV (2147483647)


vector<int> S(4 * MAX, INITV);

int n, q, N;

void update(int i, int x)
{
    i += N - 1;
    S[i] = x;
    while (i > 0) {
        i = (i - 1) / 2;
        S[i] = min(S[i * 2 + 1], S[i * 2 + 2]);
    }
}


// [s, t): area to investigate
// [l, r): area that node k represents (the area `find` is investigating now)
int find(int s, int t, int k, int l, int r)
{
    if (r <= s || t <= l)
        return INITV;

    if (s <= l && r <= t)
        return S[k];

    int u, v;
    u = find(s, t, k * 2 + 1, l, (l + r) / 2);
    v = find(s, t, k * 2 + 2, (l + r) / 2, r);
    return min(u, v);
}


int main()
{
    cin >> n >> q;
    N = 1;
    while (N < n)
        N *= 2;
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            update(x, y);
        } else {
            int r = find(x, y + 1, 0, 0, N);
            cout << r << endl;
        }
    }
}
