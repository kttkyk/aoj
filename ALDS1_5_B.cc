#include <iostream>
#include <climits>


using namespace std;

int cnt;


unsigned long L[300000], R[300000];
void merge(unsigned long A[], int l, int m, int r)
{
    for (int i = l; i < m; i++)
        L[i - l] = A[i];
    for (int i = m; i < r; i++)
        R[i - m] = A[i];
    L[m - l] = ULONG_MAX;
    R[r - m] = ULONG_MAX;

    for (int i = 0, j = 0; i + j < r - l; ) {
        cnt++;
        if (L[i] <= R[j])
            A[l + i + j] = L[i++];
        else
            A[l + i + j] = R[j++];
    }
}


void merge_sort(unsigned long A[], int l, int r) {
    if (r - l > 1) {
        int m = (l + r) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge(A, l, m, r);
    }
}


int main()
{
    int n;
    unsigned long A[500000];
    cin >> n;
    for (int i; i < n; i++)
        cin >> A[i];
    merge_sort(A, 0, n);

    for (int i; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << cnt << endl;
}
