#include <stdio.h>
#include <iostream>

#define MAX 100000

using namespace std;


int head, tail;
int queue[MAX];


void enq(int v)
{
    queue[tail] = v;
    tail = (tail + 1) % MAX;
}


int deq(void)
{
    int t = queue[head];
    head = (head + 1) % MAX;
    return t;
}


bool is_empty(void)
{
    return head == tail;
}


bool is_full(void)
{
    return head == (tail + 1) % MAX;
}


struct process {
    string name;
    int t;
};

struct process ps[MAX];


int main(void)
{
    int n, q;
    cin >> n;
    cin >> q;

    for (int i = 0; i < n; i++) {
        cin >> ps[i].name;
        cin >> ps[i].t;
        enq(i);
    }

    int passed = 0;
    while(!is_empty()) {
        int p_index = deq();
        if (ps[p_index].t > q) {
            ps[p_index].t = ps[p_index].t - q;
            enq(p_index);
            passed += q;
        } else {
            cout << ps[p_index].name << " ";
            cout << passed + ps[p_index].t << endl;
            passed += ps[p_index].t;
        }
    }
}
