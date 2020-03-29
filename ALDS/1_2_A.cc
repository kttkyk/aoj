#include <iostream>
#include <vector>


using namespace std;


using ll = long long;


void dump_array(vector<ll>& A)
{
    auto N = A.size();
    for (auto i = 0; i < N - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
}


int main()
{
    ll N;
    vector<ll> A;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    ll cnt = 0;
    for (ll i = 0; i < N - 1; i++) {
        for (ll j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                ll tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                cnt++;
            }
        }
    }

    dump_array(A);
    cout << cnt << endl;
}
