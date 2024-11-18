#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N,K;
ll MOD = 1000000000 + 7;
ll ans = 0;

ll binpower(ll a, ll b){
    ll res= 1;
    while ( b != 0){
        if(b%2 == 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b /=2 ;
    }
    return res;
}

void input() {
    cin >> N >> K;
}

void solve() {
    if(K==1){
        cout << ((N == 1) ? 1 : 0) << endl;
    } else if (N==1){
        cout << K % MOD << endl;
    } else if (N==2){
        cout << K * (K-1)%MOD << endl;
    } else {
        cout << K * (K-1) % MOD * binpower(K-2,N-2) % MOD << endl;
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}