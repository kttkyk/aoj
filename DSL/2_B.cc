#include <bits/stdc++.h>

using namespace std;

using ll = long long;


class segment_tree {
    public:
        ll size;
        vector<ll> arr;

        segment_tree(ll size);
        void add(ll i, ll x);
        ll get_sum(ll s, ll t);
        ll get_sum_sub(ll s, ll t, ll k, ll x, ll y);
};


segment_tree::segment_tree(ll size)
{
    ll n = 1;
    while (n < size)
        n *= 2;
    this->size = n;
    arr.resize(n * 2, 0);
}


void segment_tree::add(ll i, ll x)
{
    ll now = i + size - 1;
    arr[now] += x;

    while (now > 0) {
        now = (now - 1) / 2;
        arr[now] += x;
    }
}


ll segment_tree::get_sum_sub(ll s, ll t, ll k, ll x, ll y)
{
    if (y <= s || t <= x)
        return 0;
    else if (s <= x && y <= t) {
        return arr[k];
    } else {
        ll l, r;
        l = get_sum_sub(s, t, k * 2 + 1, x, (x + y) / 2);
        r = get_sum_sub(s, t, k * 2 + 2, (x + y) / 2, y);
        return l + r;
    }
}


ll segment_tree::get_sum(ll s, ll t)
{
    return get_sum_sub(s, t, 0, 0, size);
}


int main() {
    ll n, q;
    cin >> n >> q;
    segment_tree sg(n);
    for (ll i = 0; i < q; i++) {
        ll c, x, y;
        cin >> c >> x >> y;
        switch(c) {
            case 0:
                sg.add(x - 1, y);
                break;
            case 1:
                ll tmp = sg.get_sum(x - 1, y);
                cout << tmp << endl;
                break;
        }
    }
}
