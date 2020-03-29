#include <iostream>
#include <vector>
#include <string>


using namespace std;


using ll = long long;


void max_heapify(vector<ll> &A, ll i)
{
    ll li, ri, max_i;
    li = i * 2;
    ri = i * 2 + 1;
    max_i = i;

    if (li <= A.size() - 1 && A[i] < A[li]) {
        max_i = li;
    }

    if (ri <= A.size() - 1 && A[max_i] < A[ri]) {
        max_i = ri;
    }

    if (i != max_i) {
        ll t = A[max_i];
        A[max_i] = A[i];
        A[i] = t;

        max_heapify(A, max_i);
    }
}


void build_max_heap(vector<ll> &A)
{
    for (ll i = (A.size() - 1) / 2; i >= 1; i--) {
        max_heapify(A, i);
    }
}


void insert(vector<ll> &A, ll key)
{
    A.push_back(key);
    ll i = A.size() - 1;
    while (i > 1 && A[i] > A[i / 2]) {
        ll tmp = A[i];
        A[i] = A[i / 2];
        A[i / 2] = tmp;
        i /= 2;
    }
}


ll extract(vector<ll> &A)
{
    ll ret = A[1];
    A[1] = A.back();
    A.pop_back();

    max_heapify(A, 1);
    return ret;
}


int main()
{
    vector<ll> A(1);
    string cmd;

    while (true) {
        cin >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "insert") {
            ll tmp;
            cin >> tmp;
            insert(A, tmp);
        } else if (cmd == "extract") {
            cout << extract(A) << endl;
        }
    }
}
