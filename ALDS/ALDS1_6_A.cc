#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;

#define MAX 2000000

void counting_sort(unsigned int A[], unsigned int B [], int n, int k)
{
    unsigned int C[MAX];
    for (int i = 0; i < k; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    for (int i = 0; i < n; i++)
        B[--C[A[i]]] = A[i];
}


unsigned int A[MAX], B[MAX];
int main() {
    int n;

    cin >> n;

    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (k < A[i])
            k = A[i];
    }
    counting_sort(A, B, n, k);

    for (int i = 0; i < n - 1; i++)
        cout << B[i] << " ";
    cout << B[n - 1] << endl;
}
