#include <iostream>
#include <stdio.h>
using namespace std;


int main(void) 
{
    int n, count;
    int A[100];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (A[j - 1] > A[j]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << count << endl;
}
