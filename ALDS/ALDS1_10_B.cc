#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


int main()
{
    int n;
    int p[101];
    int m[101][101];

    cin >> n;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            m[i][j] = 0;

    for (int i = 0; i < n; i++)
        cin >> p[i] >> p[i + 1];

    for (int len = 1; (n - 1) - len >= 0; len++) {
        for (int i = 0; i <= (n - 1) - len; i++) {
            m[i][i + len] = INT_MAX / 3;
            for (int j = i; j < i + len; j++) {
                m[i][i + len] = min(m[i][i + len], m[i][j] + m[j + 1][i + len] + p[i] * p[j + 1] * p[i + len + 1]);
            }
        }
    }

    cout << m[0][n - 1] << endl;

    return 0;
}
