#include <bits/stdc++.h>

using namespace std;

struct Point {
    double px, py;
};

Point operator-(const Point& a1, const Point& a2) {
    return Point{ a1.px - a2.px, a1.py - a2.py };
}

// 三角関数はラジアンを受け取って、三角形の辺の比を返します。
// 逆三角関数は三角形の辺の比を受け取って、ラジアンを返します

double getangle(Point G) {
    // 点 G の偏角を求める
    if (G.py >= 0.0) {
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I) * 180.0 / 3.14159265358979;
        return kaku;
    }
    else {
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I) * 180.0 / 3.14159265358979;
        return 360.0 - kaku;
    }
}

double getangle2(double I1, double I2) {
    // [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
    // 例えば I1 = 240°、I2 = 30°のとき、求める角度は 150°
    double res = abs(I1 - I2);
    if (res >= 180.0) return 360.0 - res;
    return res;
}

int N;
Point G[2009];

double solve(int pos) {
    // 最初に偏角の昇順にソートする
    vector<double> kakuvec;
    for (int i = 0;i < N;i++) {
        Point tmp = G[i] - G[pos];
        double g = getangle(tmp);
        kakuvec.push_back(g);
    }
    // 点 A を全探索して、最も偏角の大きくなる点 C を二分探索（std::lower_bound）で求める
}


double solve_Fast() {
    double Answer = 0.0;
    for (int i = 1; i <= N; i++) {
        double ret = solve(i);
        Answer = max(Answer, ret);
    }
    return Answer;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> G[i].px >> G[i].py;
    }

    double FinalAns = solve_Fast();
    printf("%.12lf\n", FinalAns);
    return 0;
}