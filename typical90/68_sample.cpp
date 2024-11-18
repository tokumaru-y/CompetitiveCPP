#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
vector<ll>T,X,Y,V;
int N,Q;

void input() {
    cin >> N >> Q;
    T.resize(Q);X.resize(Q);Y.resize(Q);V.resize(Q);
    rep(i,Q){
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        --X[i];
        --Y[i];
    }
}

void solve() {
    vector<ll> tmp(N-1,0);
    // Yの値
    vector<ll> dif_num(N,0);
    rep(i,Q){
        if(T[i] == 0){
            tmp[X[i]] = V[i];
        }
    }
    rep(i,N-1){
        // minusはそもそも連結成分ではない 問い合わせされることはない
        dif_num[i+1] = tmp[i] - dif_num[i];
    }
    set<int> s;
    for(int i=-1;i<N;i++){
        s.insert(i);
    }
    rep(i,Q){
        if(T[i] == 0){
            s.erase(X[i]);
        } else {
            ll p = min(X[i],Y[i]);ll q = max(X[i],Y[i]);
            set<int>::iterator it = s.lower_bound(p);
            if(*it > q-1){
                ll ans = (q-p)%2==0 ? dif_num[Y[i]] + (V[i] - dif_num[X[i]]) : dif_num[Y[i]] - (V[i] - dif_num[X[i]]);
                cout << ans << endl;
            } else {
                cout << "Ambiguous" << endl;
            }
        }
    }
    // check valid
    // calc
}

void output() {}

int main()
{
    input();
    solve();
    output();
}