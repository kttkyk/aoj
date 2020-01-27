#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
    int n;
    int A[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[n-1] << endl;

    for (int i = 1; i < n; i++) {
        int j;
        int v = A[i];
        for (j = i - 1; j >= 0 && v < A[j]; j--) {
            A[j+1] = A[j];
        }
        A[j+1] = v;

        for (int j = 0; j < n - 1; j++)
            cout << A[j] << " ";
        cout << A[n - 1] << endl;
    }
}
