#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int main()
{
    int area_sum = 0;
    stack<int> slope;
    stack< pair<int, int> > ponds;
    char ch;
    for (int i = 0; cin >> ch; i++) {
        if (ch == '\\') {
            slope.push(i);
        } else if (ch == '/' && !slope.empty()) {
            int down_slope = slope.top();
            slope.pop();

            int new_area = i - down_slope;
            area_sum += new_area;

            int pond_area = new_area;
            while (!ponds.empty() && ponds.top().first > down_slope) {
                pond_area += ponds.top().second;
                ponds.pop();
            }
            ponds.push(make_pair(down_slope, pond_area));
        }
    }

    vector<int> pond_sizes;
    while (!ponds.empty()) {
        pond_sizes.push_back(ponds.top().second);
        ponds.pop();
    }

    cout << area_sum << endl;
    cout << pond_sizes.size();
    for (int i = pond_sizes.size() - 1; i >= 0; i--) {
        cout << " ";
        cout << pond_sizes[i];
    }
    cout << endl;

    return 0;
}
