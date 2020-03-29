#include <iostream>
#include <vector>


using namespace std;


using ll = long long;


ll search(vector<ll> &v, ll k)
{
    ll l, r, m;
    l = 0;
    r = v.size();

    while (l < r) {
        m = (l + r) / 2;
        if (v[m] == k) {
            return m;
        }
        if (k < v[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return -1;
}


int main()
{
    ll n, q;
    cin >> n;
    vector<ll> S(n);

    for (ll i = 0; i < n; i++)
        cin >> S[i];

    cin >> q;
    ll ans = 0;
    for (ll i = 0; i < q; i++) {
        ll tmp;
        cin >> tmp;

        if (search(S, tmp) >= 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
