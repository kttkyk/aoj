#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>


#define MAX 10000


using namespace std;
typedef pair<int, int> pi;

vector< pi > hdrs[MAX];
priority_queue< pi, vector<pi>, greater<pi> > distances;
bool is_tree[MAX];
int d[MAX];
int n;

void dijkstra()
{
    for (int i = 0; i < n; i++) {
        is_tree[i] = false;
        d[i] = INT_MAX;
    }

    distances.push(make_pair(0, 0));
    d[0] = 0;
    while (!distances.empty()) {
        // min_distance, vertex_id
        pi now = distances.top();
        distances.pop();

        if (d[now.second] < now.first)
            continue;
        is_tree[now.second] = true;

        for (vector<pi>::iterator it = hdrs[now.second].begin(); it != hdrs[now.second].end(); it++) {
            // *(it).second is same as it->second
            if (!is_tree[(*it).second] && now.first + (*it).first < d[(*it).second]) {
                d[(*it).second] = now.first + (*it).first;
                distances.push(make_pair(d[(*it).second], (*it).second));
            }
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            // cost, vertex_id
            hdrs[u].push_back(make_pair(c, v));
        }
    }

    dijkstra();

    for (int i = 0; i < n - 1; i++) {
        cout << i << " " << d[i] << endl;
    }
    cout << n - 1<< " " << d[n - 1] << endl;

    return 0;
}
