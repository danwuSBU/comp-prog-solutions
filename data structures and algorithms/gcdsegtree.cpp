#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return __gcd(abs(a), abs(b));
}

struct node {
    node *l, *r;
    ll v;
    node(node *tl, node *tr) {
        l = tl;
        r = tr;
        v = gcd(tl->v, tr->v); // change to operation
    }
    node(ll x) {
        l = r = nullptr;
        v = x;
    }
};
ll a[200000]; // max size
node* build(ll tl, ll tr) { // build in range 0 to n
    if (tl == tr - 1) {
        return new node(a[tl]);
    } else {
        ll tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm, tr));
    }
}
ll query(node *t, ll tl, ll tr, ll l, ll r) { // not right-inclusive
    if(l >= r) return 0;
    if(tl == l && tr == r) return t->v;
    ll tm = (tl + tr) / 2;
    ll r1 = query(t->l, tl, tm, l, min(r, tm));
    ll r2 = query(t->r, tm, tr, max(l, tm), r);
    return gcd(r1, r2); // change to operation
}