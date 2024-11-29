#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
unsigned long long  L,R;
ll MOD = 1000000007;
ll ans = 0;
vector<unsigned long long>ten_p(20,0);

void input() {
    cin >> L >> R;
    ten_p[0] = 1;
    for(int i=1;i<=19;i++){
        ten_p[i] = (10ULL * ten_p[i-1]);
    }
}

ll modpow(ll a,ll b, ll m){
    ll p = 1;ll q = a;
    for(int i = 0;i<30;i++){
        if((b & (1LL<< i)) != 0){
            p*= q;p %=m;
        }
        q *= q; q %= m;
    }
    return p;
}

ll Div(ll a, ll b) {
    return (a * modpow(b,MOD - 2, MOD)) % MOD;
}

ll calc(ll x){
    ll v1 = x % MOD;
    ll v2 = (x+1) % MOD;
    ll v = v1 * v2 % MOD;
    return Div(v,2);
}

void solve() {
    for(int i=1;i<=19;i++){
        unsigned long long vl = max(L, ten_p[i-1]);
        unsigned long long vr = min(R, ten_p[i] - 1ULL);
        if(vl > vr)continue;
        ll val = (calc(vr) - calc(vl - 1) + MOD) % MOD;
        ans += 1LL * i * val;
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