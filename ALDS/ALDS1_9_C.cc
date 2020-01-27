#include <iostream>
#include <climits>

using namespace std;


long A[2000001];
int H;


int parent(int i) { return i / 2; }
int left (int i) { return i * 2; }
int right (int i) { return i * 2 + 1; }


void max_heapify(int i)
{
    int max_i;
    int l, r;
    l = left(i);
    r = right(i);

    max_i = l <= H && A[l] > A[i] ? l : i;
    max_i = r <= H && A[r] > A[max_i] ? r : max_i;

    if (max_i != i) {
        long tmp = A[i];
        A[i] = A[max_i];
        A[max_i] = tmp;

        max_heapify(max_i);
    }
}


void build_max_heap()
{
    for (int i = H / 2; i >= 1; i--)
        max_heapify(i);
}


void increase_key(int i, long k)
{
    if (A[i] > k)
        return;

    A[i] = k;
    int t = i;
    while (t > 1 && A[parent(t)] < A[t]) {
        long tmp = A[t];
        A[t] = A[parent(t)];
        A[parent(t)] = tmp;

        t = parent(t);
    }
}


void insert(long k)
{
    A[++H] = LONG_MIN;
    increase_key(H, k);
}


long extract()
{
    long ret = A[1];
    A[1] = A[H--];
    max_heapify(1);
    return ret;
}


void print()
{
    for (int i = 1; i <= H; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}


int main()
{
    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'i') {
            long k;
            cin >> k;
            insert(k);
        } else if (cmd[1] == 'x') {
            cout << extract() << endl;;
        } else {
            break;
        }
        // print();
    }

    return 0;
}
