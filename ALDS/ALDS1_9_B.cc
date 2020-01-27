#include <iostream>

#define MAX 500000


using namespace std;


int parent(long A[], int i)
{
    return i / 2;
}


int left(long A[], int i)
{
    return i * 2;
}


int right(long A[], int i)
{
    return i * 2 + 1;
}

int H;
void max_heapify(long A[], int i)
{
    int l, r;
    l = left(A, i);
    r = right(A, i);

    int max_i;
    max_i = l <= H && A[l] > A[i] ? l : i;
    max_i = r <= H && A[r] > A[max_i] ? r : max_i;

    if (max_i != i) {
        int tmp = A[max_i];
        A[max_i] = A[i];
        A[i] = tmp;

        max_heapify(A, max_i);
    }
}


void build_max_heap(long A[], int H)
{
    for (int i = H / 2; i >= 1; i--)
        max_heapify(A, i);
}


long A[MAX + 1];
int main()
{
    cin >> H;
    for (int i = 1; i <= H; i++)
        cin >> A[i];

    build_max_heap(A, H);

    for (int i = 1; i <= H; i++)
        cout << " " << A[i];
    cout << endl;
}
