#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    long double T;cin >> T;
    long double L, X, Y;cin >> L >> X >> Y;
    int Q;cin >> Q;
    while (Q > 0) {
        Q--;
        long double E;cin >> E;
        long double theta = E / T * 2.0 * M_PI;
        long double a = -(L / 2.0) * (sin(theta));
        long double b = (L / 2.0) - (L / 2.0) * (cos(theta));
        long double x = X * X;
        long double y = (Y - a) * (Y - a);

        long double s = sqrt(x + y);
        long double ans_theta = atan2(b, s);
        long double ans = ans_theta * 180.0L / M_PI;
        printf("%.16Lf\n", ans);
    }
}