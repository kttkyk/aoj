#include <bits/stdc++.h>


using namespace std;


using ll = long long;


class segment_tree {
    public:
        ll size;
        vector<ll> A;
        segment_tree(ll size);
        void update(ll i, ll x);
        ll find(ll s, ll t);
        ll find_sub(ll s, ll t, ll i, ll l, ll r);
};


segment_tree::segment_tree(ll size)
{
    ll tmp = 1;
    while (tmp < size)
        tmp *= 2;
    this->size = tmp;
    A.resize(tmp * 2 - 1, (1LL << 31) - 1);
}

void segment_tree::update(ll i, ll x)
{
    ll now = i + size - 1;
    A[now] = x;
    while (now > 0) {
        now = (now - 1) / 2;
        A[now] = min(A[2 * now + 1], A[2 * now + 2]);
    }
}


/*
 * [a, b): The area that we want to know the answer of.
 * [l, r): The area that we are currently checking.
 * k: The index of segment tree array (A),
 *      that corresponds to [l, r)
 */
ll segment_tree::find_sub(ll a, ll b, ll k, ll l, ll r)
{
    if (r <= a || b <= l)
        return (1LL << 31) - 1;
    else if (a <= l && r <= b)
        return A[k];
    else {
        ll x, y;
        x = find_sub(a, b, k * 2 + 1, l, (l + r) / 2);
        y = find_sub(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(x, y);
    }
}


ll segment_tree::find(ll s, ll t)
{
    return find_sub(s, t, 0, 0, size);
}


int main() {
    ll n, q;
    cin >> n >> q;

    segment_tree st(n);
    for (int i = 0; i < q; i++) {
        ll c, x, y;
        cin >> c >> x >> y;
        switch(c) {
            case 0:
                st.update(x, y);
                break;
            case 1:
                ll res = st.find(x, y + 1);
                cout << res << endl;
                break;
        }
    }
}
