#include <iostream>

using namespace std;


bool check(int acc, int depth, int ans, int A[], int n)
{
    if (depth == n)
        return false;
    if (A[depth] + acc == ans)
        return true;

    return check(acc + A[depth], depth + 1, ans, A, n) || check(acc, depth + 1, ans, A, n);
}


int main(void)
{
    int n, q;
    int A[20], M[200];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int ans;
        cin >> ans;
        if (check(0, 0, ans, A, n))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
