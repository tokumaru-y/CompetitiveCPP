#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N,Q;
vector<ll>X,Y,Z,W;
ll ans = 1;


void input() {
    cin >> N >> Q;
    X.resize(Q);
    Y.resize(Q);
    Z.resize(Q);
    W.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--;
        Y[i]--;
        Z[i]--;
    }
}

void check(vector<ll> w) {
    ll cnt = 0;
    for(int bit=0;bit < (1<<N);bit++){
        bool is_ok = true;

        for(int i = 0;i<Q;i++){
            if(w[i] == 0){
                if((bit & (1 << X[i])) > 0 || (bit & (1 << Y[i])) > 0 || (bit & (1 << Z[i])) > 0 ){
                    is_ok = false;
                    break;
                }
            } else {
                if((bit & (1 << X[i]))== 0 && (bit & (1 << Y[i])) == 0 && (bit & (1 << Z[i])) == 0  ){
                    is_ok = false;
                    break;
                }
            }
        }
        if(is_ok){
            cnt++;
        }
    }

    ans = ans * cnt % MOD;
    ans %= MOD;
}




void solve() {
    for(int i=0;i<60;i++){
        vector<ll> w(Q,0);
        rep(j,Q){

            w[j] = ((W[j] / (1LL << i)) % 2LL);
        };
        check(w);
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