#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;


using ll = long long;


const ll MAX = 100;


int main()
{
    ll n;

    cin >> n;
    vector<vector<ll>> m(n + 1);
    for (ll i = 0; i <= n; i++)
        m[i].resize(n + 1);
    vector<pair<ll, ll>> M;
    for (ll i = 0; i < n; i++) {
        ll r, c;
        cin >> r >> c;
        M.push_back(make_pair(r, c));
    }

    for (ll i = 0; i < n; i++) {
        m[i][i] += 0;
    }

    for (ll i = 0; i < n - 1; i++) {
        m[i][i + 1] += M[i].first * M[i].second * M[i + 1].second;
    }

    for (ll len = 2; len < n; len++) {
        for (ll l = 0; l < n - len; l++) {
            ll r = l + len;
            m[l][r] = LONG_LONG_MAX;
            for (ll mid = l; mid < r; mid++) {
                ll tmp = M[l].first * M[mid].second * M[r].second;
                // cout << tmp << endl;
                m[l][r] = min(m[l][r], tmp + m[l][mid] + m[mid + 1][r]);
            }
        }
    }
    cout << m[0][n - 1] << endl;
}
