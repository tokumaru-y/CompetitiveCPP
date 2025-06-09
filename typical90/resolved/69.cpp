#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
unsigned long long MOD = 1000000007;
unsigned long long N;
unsigned long long K;
unsigned long long ans = 1ULL;

void input() {
    cin >> N >> K;
}

void calc() {
    unsigned long long a = K-2ULL;
    unsigned long long n = N-2ULL;
    ll tmp = 1;
    rep(i, 61){
        if((n & (1LL << i)) > 0) {
            ans *= a;
            ans %= MOD;
        }
        a = a * a % MOD;
        a %= MOD;
    }
}

void solve() {
    if(K==1){
        ans = (N == 1) ? 1 : 0;
        return;
    } else if (N==1){
        ans = K % MOD;
        return;
    } else if (N==2){
        ans = K * (K-1) % MOD;
        return;
    }
    ans *= K;
    ans %= MOD;
    ans *= (K - 1ULL);
    ans %= MOD;
    calc();
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