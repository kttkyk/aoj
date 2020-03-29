#include <iostream>
#include <cstring>
#include <string>

using namespace std;


using ll = long long;


ll c[1001][1001];
void solve()
{
    string X, Y;
    cin >> X >> Y;

    memset(c, 0, sizeof(c));
    for (ll i = 0; i <= X.length(); i++)
        c[i][0] = 0;
    for (ll i = 0; i <= Y.length(); i++)
        c[0][i] = 0;

    for (ll i = 1; i <= X.length(); i++) {
        for (ll j = 1; j <= Y.length(); j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    cout << c[X.length()][Y.length()] << endl;
}


int main()
{
    ll q;
    ll c[151][151];

    cin >> q;
    for (ll i = 0; i < q; i++) {
        solve();
    }
}
