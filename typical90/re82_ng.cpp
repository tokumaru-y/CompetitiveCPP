#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll L,R;
ll ans;

void input() {
    cin >> L >> R;
}

void solve() {
    ans = 0;
    ll num = 0;
    ll modinv2 = 500000004;
    for(int i =1; i<=18;i++){
        if(num == 0){
            num = 1;
        } else {
            num *= 10;
        }
        if(num > R)break;
        if((L + 1) / 10 > num)continue;
        ll left = max(L, num);
        ll right = i == 18 ? min(R,1000000000000000000LL) : min(R, num * 10 - 1);
        ll sum_r = ((right % MOD)* (right % MOD +1))% MOD * modinv2 % MOD;
        ll sum_l = ((left - 1) % MOD) * ((left) % MOD ) % MOD * modinv2 % MOD;
        ans += (sum_r - sum_l + MOD) % MOD * i;
        ans %=MOD;
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