/* Shell Sort */


#include <iostream>
#include <stdio.h>

using namespace std;


int cnt = 0;


void insertionsort(int A[], int n, int g)
{
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j;
        j = i - g;
        while (j >= 0 && v < A[j]) {
            if (A[j] < v)
                break;
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}


void output(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[n - 1]);
}


int main(void) {
    int n;
    int A[100000];
    int G[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }

    int m = 0, tmp;
    G[m] = 1;
    while((tmp = G[m] * 3 + 1) < n) {
        G[++m] = tmp;
    }

    for (int i = m; i >= 0; i--)
        insertionsort(A, n, G[i]);

    cout << m + 1 << endl;
    for (int i = m; i > 0; i--)
        printf("%d ", G[i]);
    printf("%d\n", G[0]);
    cout << cnt << endl;

    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
}
