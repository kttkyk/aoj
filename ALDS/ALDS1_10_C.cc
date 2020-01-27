#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;


int m[MAX + 2][MAX + 2];
int lcs(string x, string y)
{
    for (int i = 0; i <= y.length(); i++)
        for (int j = 0; j <= x.length(); j++)
            m[i][j] = 0;

    for (int i = 1; i <= y.length(); i++) {
        for (int j = 1; j <= x.length(); j++) {
            if (x[j - 1] == y[i - 1]) {
                m[i][j] = m[i - 1][j - 1] + 1;
            } else {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    return m[y.length()][x.length()];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        cout << lcs(x, y) << endl;
    }
}
