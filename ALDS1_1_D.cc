#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;


int main(void)
{
    int R[MAX], n;

    cin >> n;
    for (int i; i < n; i++) cin >> R[i];

    int max_profit = -2000000000;
    int min_rate = R[0];

    for (int i = 1; i < n; i++) {
        max_profit = max(max_profit, R[i] - min_rate);
        min_rate = min(min_rate, R[i]);
    }

    cout << max_profit << endl;

    return 0;
}
