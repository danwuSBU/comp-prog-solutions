//#include <iostream>
//using namespace std;
//
//// fast integer in
//void fastscan(int& ret) {
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
//    // use "\n" instead of cout << endl
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    return 0;
//}