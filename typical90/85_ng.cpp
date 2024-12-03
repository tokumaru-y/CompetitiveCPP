#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll K;
ll ans = 0;

void input() {
    cin >> K;
}

void solve() {
    vector<ll>div;
    for(ll i=1;i*i<=K;i++){
        if(K%i==0){
            div.push_back(i);
            if(i != (K/i))div.push_back(K/i);
        }
    }
    sort(div.begin(),div.end());
    rep(i,div.size()){
        for(int j=i;j<div.size();j++){
            ll a = div[i];ll b=div[j];ll c =0;
            if((K/a) < b)continue;
            if(K%(a*b) != 0LL)continue;
            c = K / (a * b);
            if(b<=c)ans++; 
        }
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