#include <iostream>

using namespace std;


int partition(unsigned long A[], int l, int r)
{
    unsigned long pivot = A[r - 1];
    unsigned long tmp;
    int cnt = 0;
    int i, j;
    for (i = l, j = l; i < r - 1; i++) {
        if (A[i] <= pivot) {
            // gather numbers smaller than the pivot to the left side
            tmp = A[i];
            A[i] = A[j];
            A[j++] = tmp;
        }
    }
    A[r - 1] = A[j];
    A[j] = pivot;
    return j;
}


int main()
{
    int n;
    unsigned long A[100000];

    cin >> n;
    for (int i; i < n; i++)
        cin >> A[i];

    int pivot_i = partition(A, 0, n);

    for (int i; i < n - 1; i++)
        if (i == pivot_i)
            cout << "[" << A[i] << "] ";
        else
            cout << A[i] << " ";
    cout << A[n - 1] << endl;
}
