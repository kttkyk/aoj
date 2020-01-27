#include <iostream>
#include <climits>

using namespace std;


#define MAX 200000


unsigned long cnt_inv = 0;
unsigned long L[MAX / 2 + 1], R[MAX / 2 + 1];
void merge(unsigned long A[], int l, int m, int r)
{
    for (int i = l; i < m; i++)
        L[i - l] = A[i];
    for (int i = m; i < r; i++)
        R[i - m] = A[i];
    L[m - l] = ULONG_MAX;
    R[r - m] = ULONG_MAX;

    int i, j;
    for (i = j = 0; i + j < r - l; ) {
        if (L[i] <= R[j]) {
            A[l + i + j] = L[i++];
        } else {
            A[l + i + j] = R[j++];
            cnt_inv += (m - l - i);
        }
    }
}


void merge_sort(unsigned long A[], int l, int r)
{
    if (r - l > 1) {
        int m = (l + r) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge(A, l, m, r);
    }
}


unsigned long A[MAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    merge_sort(A, 0, n);
    cout << cnt_inv << endl;

    return 0;
}
