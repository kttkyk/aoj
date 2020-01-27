#include <iostream>
#include <stdio.h>

using namespace std;


struct card {
    char suit;
    char val;
};


void swap(struct card *a, int i, int j)
{
    struct card tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


void bubble_sort(struct card *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1].val > a[j].val) {
                swap(a, j - 1, j);
            }
        }
    }
}


void selection_sort(struct card *a, int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (a[min_index].val > a[j].val)
                min_index = j;
        }
        if(min_index != i)
            swap(a, min_index, i);
    }
}


void copy_deck(struct card *a, struct card *b, int n) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}


void output(struct card *a, int n) {
    for (int i = 0; i < n - 1; i++)
        printf("%c%c ", a[i].suit, a[i].val);
    printf("%c%c\n", a[n - 1].suit, a[n - 1].val);
}


int main(void)
{
    int n;
    char c[2];
    struct card cards[36];
    struct card bubble_deck[36];
    struct card selection_deck[36];


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cards[i].suit = c[0];
        cards[i].val = c[1];
    }

    copy_deck(cards, bubble_deck, n);
    copy_deck(cards, selection_deck, n);

    bubble_sort(bubble_deck, n);
    output(bubble_deck, n);
    cout << "Stable" << endl;

    selection_sort(selection_deck, n);
    output(selection_deck, n);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (bubble_deck[i].suit != selection_deck[i].suit) {
            stable = false;
            break;
        }
    }

    if (stable)
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
}
