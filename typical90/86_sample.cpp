#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,Q;
vector<ll>X,Y,Z,W;
vector<ll>x,y,z,w;
ll ans = 1;
ll MOD = 1000000007;

void input() {
    cin >> N >> Q;
    X.resize(100);Y.resize(100);Z.resize(100);W.resize(100);
    x.resize(100);y.resize(100);z.resize(100);w.resize(100);    
    rep(i,Q){
        cin >> X[i+1] >> Y[i+1] >> Z[i+1] >> W[i+1];
    }
}

ll bit_zentansaku() {
    ll ways = 0;
    rep(i,(1<<N)){
        ll bit[15];
        rep(j,N){bit[j+1] = (i / (1 << j)) % 2;}
        bool flag = true;
        for(int j=1;j<=Q;j++){
            if(((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != w[j])flag = false;
        }
        if(flag == true)ways++;
    }
    return ways;
}


void solve() {
    rep(i,60){
        for(int j=1;j<=Q;j++){
            x[j]=X[j];y[j]=Y[j];z[j]=Z[j];
            w[j] = (W[j] / (1LL << i)) % 2LL;
        }
        ll ret = bit_zentansaku();
        ans *= ret;
        ans %= MOD;
    }
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