#include <iostream>
#include <string>
#include <queue>


using namespace std;


using ll = long long;


class process {
    public:
        string name;
        ll time;
};


int main()
{
    queue<process*> ps;
    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        process* tmp = new process;
        cin >> tmp->name >> tmp->time;
        ps.push(tmp);
    }

    ll now = 0;
    while (!ps.empty()) {
        process* tmp = ps.front();
        ps.pop();

        if (tmp->time > q) {
            tmp->time -= q;
            ps.push(tmp);
            now += q;
        } else {
            now += tmp->time;
            tmp->time = 0;
            cout << tmp->name << " " << now << endl;
            delete tmp;
        }
    }
}
