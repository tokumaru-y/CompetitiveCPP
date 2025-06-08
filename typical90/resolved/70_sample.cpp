#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
vector<ll> X, Y;
vector<ll> p;
vector<ll> w;
ll ans = 0;

void input() {
    cin >> N;
    X.resize(N);
    Y.resize(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
    }
}

void solve() {
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int half = N / 2;
    if(N==1)half = 1;
    ll tmp1=0;
    ll tmp2=0;
    rep(i,N){
        tmp1+= abs(X[i] - X[half]);
        tmp2+= abs(X[i] - X[half-1]);
    }
    ans += min(tmp1, tmp2);

    tmp1=0;
    tmp2=0;
    rep(i,N){
        tmp1+= abs(Y[i] - Y[half]);
        tmp2+= abs(Y[i] - Y[half-1]);
    }
    ans += min(tmp1, tmp2);
}

void output() {
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}