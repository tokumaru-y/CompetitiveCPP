#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q;cin >> N >> Q;
    vector<ll>A(N);vector<ll>B(N);
    ll min_A = 2000000000;ll max_A = -2000000000;
    ll min_B = 2000000000;ll max_B = -2000000000;
    rep(i, N) {
        ll x, y;cin >> x >> y;
        ll a = x + y;
        ll b = x - y;
        A[i] = a;B[i] = b;
        min_A = min(A[i], min_A);
        max_A = max(A[i], max_A);
        min_B = min(B[i], min_B);
        max_B = max(B[i], max_B);
    }

    rep(i, Q) {
        ll q;cin >> q;q--;
        ll x = A[q];ll y = B[q];
        ll max_x = max(x - min_A, max_A - x);
        ll max_y = max(y - min_B, max_B - y);
        cout << max(max_x, max_y) << endl;
    }


}