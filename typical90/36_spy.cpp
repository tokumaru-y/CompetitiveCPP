#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,Q;
vector<ll>X,Y;
vector<ll>plusXY,difXY;


void input() {
    cin >> N >> Q;
    rep(i,N){
        ll x,y;cin >> x >>y;
        X.push_back(x);Y.push_back(y);
    }
}

void solve() {
    rep(i,N){
        ll t = X[i] + Y[i];
        ll tt = X[i] - Y[i];
        plusXY.push_back(t);
        difXY.push_back(tt);
    }
    sort(plusXY.begin(),plusXY.end());sort(difXY.begin(),difXY.end());
    ll pmax = plusXY[plusXY.size() - 1];ll pmin = plusXY[0];
    ll dmax = difXY[difXY.size() - 1];ll dmin = difXY[0];

    rep(i,Q){
        int q;cin >> q;q--;
        ll t = X[q] + Y[q];
        ll tt = X[q] - Y[q];
        ll ans = max(max(abs(t - pmax),abs(t - pmin)),max(abs(tt - dmax),abs(tt - dmin)));
        cout << ans << endl;
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}