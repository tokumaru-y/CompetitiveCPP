#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q;cin >> N >> Q;
    vector<int>A(N);rep(i, N)cin >> A[i];
    int t2Cnt = 0;
    rep(i, Q) {
        int t, x, y;cin >> t >> x >> y;x--;y--;
        if (t == 1) {
            int nx = (x + t2Cnt) % N;int ny = (y + t2Cnt) % N;
            swap(A[nx], A[ny]);
        }
        else if (t == 2) {
            t2Cnt = (t2Cnt - 1 + N) % N;
        }
        else {
            int ind = (x + t2Cnt) % N;
            cout << A[ind] << endl;
        }
    }
}