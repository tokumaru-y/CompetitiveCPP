#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<ll> X,Y;
void input() {
    cin >> N;
    X.resize(N);Y.resize(N);
    rep(i,N){    
        cin >> X[i] >> Y[i];
    }
}

void solve() {
    sort(X.begin(), X.end());
    vector<ll> sum_x(N+1,0);
    vector<ll> sum_x_rev(N+1,0);
    rep(i,N-1){
        sum_x[i+1] = sum_x[i] + (i+1) * abs(X[i+1] - X[i]);
        sum_x_rev[i+1] = sum_x_rev[i] + (i+1) * abs(X[N-i-1] - X[N-i-2]);
    }

    sort(Y.begin(), Y.end());
    vector<ll> sum_y(N+1,0);
    vector<ll> sum_y_rev(N+1,0);
    rep(i,N-1){
        sum_y[i+1] = sum_y[i] + (i+1) * abs(Y[i+1] - Y[i]);
        sum_y_rev[i+1] = sum_y_rev[i] + (i+1) * abs(Y[N-i-1] - Y[N-i-2]);
    }

    ll min_sum_x = (1LL<<63)-1;
    ll min_sum_y = (1LL<<63)-1;
    for(int i = 0;i<(N);i++){
        ll tmpx = sum_x[i] + sum_x[N-i-1];
        ll tmpy = sum_y[i] + sum_y[N-i-1];
        if(tmpx < min_sum_x){
            min_sum_x = tmpx;
        }
        if(tmpy < min_sum_y){
            min_sum_y = tmpy;
        }
    }
    cout << min_sum_x + min_sum_y << endl;
}

void output() {
}

int main()
{
    input();
    solve();
    output();
}