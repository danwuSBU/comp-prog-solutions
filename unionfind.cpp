////https://open.kattis.com/problems/unionfind
//#include <iostream>
//
//using namespace std;
//
//class union_find
//{
//    int* id, cnt, * sz;
//public:
//    // Create an empty union find data structure with N isolated sets.
//    union_find(int N) {
//        cnt = N; id = new int[N]; sz = new int[N];
//        for (int i = 0; i < N; i++)  id[i] = i, sz[i] = 1;
//    }
//    ~union_find() { delete[] id; delete[] sz; }
//
//    // Return the id of component corresponding to object p.
//    int find(int p) {
//        int root = p;
//        while (root != id[root])    root = id[root];
//        while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
//        return root;
//    }
//    // Replace sets containing x and y with their union.
//    void merge(int x, int y) {
//        int i = find(x); int j = find(y); if (i == j) return;
//        // make smaller root point to larger one
//        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
//        else { id[j] = i, sz[i] += sz[j]; }
//        cnt--;
//    }
//    // Are objects x and y in the same set?
//    bool connected(int x, int y) { return find(x) == find(y); }
//    // Return the number of disjoint sets.
//    int count() { return cnt; }
//};
//
//void readint(int& ret) {
//    ret = 0;
//    char r;
//    bool start = false, neg = false;
//    while (true) {
//        r = getchar();
//        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
//            continue;
//        }
//        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
//            break;
//        }
//        if (start)ret *= 10;
//        start = true;
//        if (r == '-')neg = true;
//        else ret += r - '0';
//    }
//    if (neg) ret *= -1;
//}
//
//int main()
//{
//    int n, q;
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    readint(n);
//    readint(q);
//
//    union_find uf = union_find(n + 1);
//    char qr;
//    int a, b;
//    for (int i = 0; i < q; i++)
//    {
//        qr = getchar();
//        readint(a);
//        readint(b);
//        if (qr == '?')
//        {
//            if (uf.connected(a, b))
//            {
//                cout << "yes" << endl;
//            }
//            else
//            {
//                cout << "no" << endl;
//            }
//        }
//        else
//        {
//            uf.merge(a, b);
//        }
//    }
//    return 0;
//}