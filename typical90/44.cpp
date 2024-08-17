#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q;cin >> N >> Q;
    deque<int> A;
    rep(i, N) {
        int a;cin >> a;A.push_back(a);
    }
    rep(i, Q) {
        int t, x, y;cin >> t >> x >> y;x--;y--;
        if (t == 1) {
            int tmp = A[x];
            A[x] = A[y];A[y] = tmp;
        }
        else if (t == 2) {
            int tmp = A.back();A.pop_back();
            A.push_front(tmp);
        }
        else {
            cout << A[x] << endl;
        }
    }
}