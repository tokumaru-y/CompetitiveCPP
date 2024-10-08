#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int Q;
long double T, L, X, Y, E;
long double PI = 3.14159265358979;

long double query(long double E) {
    long double cx = 0;
    // 角度1度あたり、ラジアンの値はPI / 180.今回は360度のラジアンが欲しいため((I / T) * 360) * PI / 180 = 2.0 * PIとなっている。
    long double cy = -(L / 2.0) * sin(E / T * 2.0 * PI);
    long double cz = (L / 2.0) - (L / 2.0) * cos(E / T * 2.0 * PI);
    long double d1 = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));
    long double d2 = cz;
    // 返却値はラジアン
    long double kaku = atan2(d2, d1);
    // 欲しいのは角度. 1(ラジアン)=1(度) * PI / 180.
    return kaku * 180.0L / PI;
}


int main()
{
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> E;
        printf("%.12Lf\n", query(E));
    }
    return 0;
}