#include <iostream>
#include <vector>


using namespace std;


using ll = long long;


bool search(vector<ll> &A, ll m, ll d)
{
    if (m == 0)
        return true;
    else if (d < 0)
        return false;

    bool ret = search(A, m - A[d], d - 1);
    ret = ret || search(A, m, d - 1);
    return ret;
}


int main()
{
    ll n, q;
    cin >> n;

    vector<ll> A(n);

    for (ll i = 0; i < n; i++)
        cin >> A[i];

    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll tmp;
        cin >> tmp;
        if (search(A, tmp, n)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
