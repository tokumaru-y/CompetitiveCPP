#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long double PI = 3.14159265358979;

int main()
{
    int T;cin >> T;long double  L, X, Y;cin >> L >> X >> Y;
    int Q;cin >> Q;
    while (Q > 0) {
        Q--;
        long double e;cin >> e;
        long double a = -(L / 2.0) * sin(e / T * 2.0 * PI);
        long double b = (L / 2.0) - (L / 2.0) * cos(e / T * 2.0 * PI);
        long double s = sqrt(X * X + (Y - a) * (Y - a));
        long double t = atan2(b, s);
        long double ans = t * 180.0L / PI;
        printf("%.12Lf\n", ans);
    }
}