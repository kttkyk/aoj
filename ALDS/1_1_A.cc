#include <iostream>
#include <vector>


using namespace std;


using ll = long long;


void dump_array(vector<ll>& A, ll N)
{
    for (auto i = 0; i < N - 1; i++)
        cout << A[i] << " ";
    cout << A[N - 1] << endl;
}


int main()
{
    vector<ll> A;
    ll N;

    cin >> N;
    for (auto i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A.push_back(x);
    }

    for (auto i = 1; i < N; i++) {
        dump_array(A, N);

        auto j = i;
        auto tmp = A[j];
        while (j > 0 && !(A[j - 1] <= tmp)) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
    }

    dump_array(A, N);
}
