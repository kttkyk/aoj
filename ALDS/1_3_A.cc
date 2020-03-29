#include <iostream>
#include <stack>
#include <sstream>


using namespace std;


using ll = long long;


int main()
{
    stack<int> s;
    ll ch;
    string line, tok;

    getline(cin, line);
    istringstream iss(line);

    while (iss >> tok) {
        ll x, y;
        if (tok == "+") {
            x = s.top(); s.pop();
            y = s.top(); s.pop();
            s.push(x + y);
        } else if (tok == "-") {
            x = s.top(); s.pop();
            y = s.top(); s.pop();
            s.push(y - x);
        } else if (tok == "*") {
            x = s.top(); s.pop();
            y = s.top(); s.pop();
            s.push(x * y);
        } else {
            ch = stoll(tok);
            s.push(stoll(tok));
        }
    }
    cout << s.top() << endl;
}
