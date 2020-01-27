#include <iostream>

using namespace std;


int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return i * 2;
}

int right(int i)
{
    return i * 2 + 1;
}


int main()
{
    int H, A[250 + 1];
    cin >> H;

    for (int i = 1; i <= H; i++)
        cin >> A[i];

    for (int i = 1; i <= H; i++) {
        int t;
        cout << "node " << i;
        cout << ": key = " << A[i] << ", ";

        if ((t = parent(i)) > 0)
            cout << "parent key = " << A[t] << ", ";
        if ((t = left(i)) <= H)
            cout << "left key = " << A[t] << ", ";
        if ((t = right(i)) <= H)
            cout << "right key = " << A[t] << ", ";
        cout << endl;
    }

    return 0;
}
