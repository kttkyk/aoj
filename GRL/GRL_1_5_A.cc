#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


static const int MAX = 100000;

vector< pair<int, int> > graph[MAX];


vector<int> bfs(int start)
{
    vector<int> d(MAX, 0);
    vector<bool> discovered(MAX, false);
    queue<int> visiting;


    visiting.push(start);
    discovered[start] = true;

    while (!visiting.empty()) {
        int now = visiting.front();
        visiting.pop();

        for (auto it = graph[now].begin(); it != graph[now].end(); ++it) {
            if (!discovered[(*it).first]) {
                discovered[(*it).first] = true;
                visiting.push((*it).first);
                d[(*it).first] = d[now] + (*it).second;
            }
        }
    }

    return d;
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        graph[s].push_back(make_pair(t, w));
        graph[t].push_back(make_pair(s, w));
    }

    vector<int> d = bfs(0);
    int x = distance(d.begin(), max_element(d.begin(), d.end()));

    d = bfs(x);
    int diameter = *max_element(d.begin(), d.end());
    cout << diameter << endl;

    return 0;
}
