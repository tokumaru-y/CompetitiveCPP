#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N;
ll ans = 0;

void input() {
    cin >> N;
}

void solve() {
    ll limit = N;
    ll cnt = 0;
    for(ll i=2;i*i<=limit;i++){
        if(N%i!=0)continue;
        while(N%i==0){
            N/=i;
            cnt++;
        }
        if(N==1)break;
    }
    if(N!=1){
        cnt++;
    }
    ll tmp = 1;
    while(tmp < cnt){
        tmp *= 2;
        ans +=1;
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