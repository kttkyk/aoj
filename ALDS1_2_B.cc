#include <iostream>
#include <algorithm>

using namespace std;


int main(void)
{
    int n, count = 0;
    int A[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (A[min_index] > A[j])
                min_index = j;
        }
        if (min_index != i) {
            int tmp = A[min_index];
            A[min_index] = A[i];
            A[i] = tmp;
            count++;
        }
    }

    for (int i = 0; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << count << endl;
}
