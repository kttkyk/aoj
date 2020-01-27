#include <iostream>

using namespace std;


int bin_search(int a[], int n, int v)
{
    int m, l, r;
    l = 0;
    r = n;
    m = (l + r) / 2;

    while (a[m] != v && l != r) {
        if (a[m] < v) {
            l = m + 1;
        } else if (a[m] > v) {
            r = m;
        }
        m = (l + r) / 2;
    }

    return l == r ? -1 : m;
}


int main()
{
    int n, q;
    int S[100000];
    int T[50000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> T[i];

    int c = 0;
    for (int i = 0; i < q; i++)
        if (bin_search(S, n, T[i]) >= 0)
            c++;
    cout << c << endl;

    return 0;
}
