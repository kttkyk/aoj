#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;


long long load(unsigned long long w[], int n, int k, unsigned long long p)
{
    int trucks_left = k - 1;
    unsigned long long space = p;
    int i;
    for (i = 0; i < n; ) {
        if (space < w[i] && trucks_left == 0)
            break;

        if (space < w[i] && trucks_left > 0) {
            trucks_left--;
            space = p;
        }
        if (space >= w[i]) {
            space -= w[i++];
        }
    }

    if (i == n && trucks_left >= 0) // remains
        return (trucks_left * p) + space;
    else // shortage
        return -1 * accumulate(w + i, w + n, 0);
}


int check(unsigned long long w[], int n, int k, unsigned long long p)
{
    long long tmp = load(w, n, k, p);
    if (tmp < 0) { // short
        return -1;
    }

    long long prev = load(w, n, k, p - 1);
    if (prev >= 0){ // too much
        return 1;
    }

    return 0;
}


int bin_search(unsigned long long w[], int n, int k)
{
    unsigned long long m, l, r;
    l = 0;
    r = 100000 * 10000;
    m = (l + r) / 2;

    int tmp;
    while ((tmp = check(w, n, k, m)) != 0 && l != r) {
        if (tmp > 0) { // too much
            r = m;
        } else if (tmp < 0) { // short
            l = m + 1;
        }
        m = (l + r) / 2;
    }
    return m;
}


int main()
{
    int n, k;
    unsigned long long w[100000];

    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
        scanf("%llu", w + i);
    int out = bin_search(w, n, k);
    cout << out << endl;

    return 0;
}
