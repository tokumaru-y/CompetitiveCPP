//三角関数　特に度数法と弧度法の関係・定義について整理すること
// https://note.com/daikiasanuma/n/n1409d5f1a980
// https://qiita.com/Ninagawa123/items/9667e5292b67946bdfc9#%E3%83%A9%E3%82%B8%E3%82%A2%E3%83%B3%E3%81%AE%E5%AE%9A%E7%BE%A9 こちらの解釈がしっくりきた。
// まず、πの定義から　円周の長さ/円の直径=πとなる　すると、
// 弧度法の概念を適応させると　360°= π * ( 2 * 半径)=π*(2 * ラジアン)
// 180°=πラジアン　となる。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
long double T,L,X,Y;
ll Q;
vector<long double>E;

void input() {
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;
    rep(i,Q){
        long double e;cin >> e;
        E.push_back(e);
    }
}

void solve() {
    for(long double e: E){
        long double theta = (e / T) * 2.0 * M_PI;
        long double s = -(L / 2.0) * sin(theta);
        long double t = (L / 2.0) - (L/2.0)*cos(theta);
        long double ap = sqrt(X*X + ((Y-s)*(Y-s)));
        long double ans_theta = atan2(t,ap);
        long double ans = ans_theta * (180.0L / M_PI);
        printf("%.16Lf\n", ans);
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}