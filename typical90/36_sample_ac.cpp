#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll N, X[1 << 18], Y[1 << 18];
ll Q, T[1 << 18];
ll min_X = (1LL << 60), max_X = -(1LL << 60);
ll min_Y = (1LL << 60), max_Y = -(1LL << 60);

int main()
{
    cin >> N >> Q;
    for (int i = 1;i <= N;i++)cin >> X[i] >> Y[i];
    for (int i = 1;i <= Q;i++)cin >> T[i];

    for (int i = 1;i <= N;i++) {
        ll p1 = X[i] + Y[i];
        ll p2 = X[i] - Y[i];
        X[i] = p1;Y[i] = p2;
        min_X = min(min_X, X[i]);
        max_X = max(max_X, X[i]);
        min_Y = min(min_Y, Y[i]);
        max_Y = max(max_Y, Y[i]);
    }

    for (int i = 1;i <= Q;i++) {
        ll ret1 = abs(X[T[i]] - min_X);
        ll ret2 = abs(X[T[i]] - max_X);
        ll ret3 = abs(Y[T[i]] - min_Y);
        ll ret4 = abs(Y[T[i]] - max_Y);

        cout << max({ ret1,ret2,ret3, ret4 }) << endl;
    }
}