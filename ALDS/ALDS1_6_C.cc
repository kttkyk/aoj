#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;


struct card {
    char suit;
    unsigned long num;
    int i;
};


int partition(card A[], int l, int r)
{
    card pivot = A[r - 1];
    int i, j;
    for(i = j = l; i < r - 1; i++) {
        if (A[i].num <= pivot.num) {
            card tmp = A[i];
            A[i] = A[j];
            A[j++] = tmp;
        }
    }
    A[r - 1] = A[j];
    A[j] = pivot;
    return j;
}


void quick_sort(card A[], int l, int r)
{
    if (r - l > 1) {
        int pivot_index = partition(A, l, r);
        quick_sort(A, l, pivot_index);
        quick_sort(A, pivot_index + 1, r);
    }
}

int main()
{
    int n;
    char ch;
    unsigned long v;
    card qcards[100000];

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &ch);
        scanf("%lu", &v);
        getchar();

        qcards[i].suit = ch;
        qcards[i].num = v;
        qcards[i].i = i;
    }

    quick_sort(qcards, 0, n);

    int i;
    for (i = 0; i < n; i++)
        if (qcards[i - 1].num == qcards[i].num && qcards[i - 1].i > qcards[i].i)
            break;

    if (i == n)
        printf("Stable\n");
    else
        printf("Not stable\n");

    for (i = 0; i < n - 1; i++) {
        printf("%c %lu\n", qcards[i].suit, qcards[i].num);
    }
    printf("%c %lu\n", qcards[n - 1].suit, qcards[n - 1].num);
}
