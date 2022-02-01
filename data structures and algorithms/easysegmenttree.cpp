#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l, *r;
    int v;
    node(node *tl, node *tr) {
        l = tl;
        r = tr;
        v = __gcd(tl->v, tr->v); // change to operation
    }
    node(int x) {
        l = r = nullptr;
        v = x;
    }
};
int a[200000]; // max size
node* build(int tl, int tr) { // build in range 0 to n
    if (tl == tr - 1) {
        return new node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm, tr));
    }
}
int query(node *t, int tl, int tr, int l, int r) { // not right-inclusive
    if(l >= r) return 0;
    if(tl == l && tr == r) return t->v;
    int tm = (tl + tr) / 2;
    int r1 = query(t->l, tl, tm, l, min(r, tm));
    int r2 = query(t->r, tm, tr, max(l, tm), r);
    return gcd(r1, r2); // change to operation
}