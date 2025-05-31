#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
unsigned long long MOD = 1000000007;
ll ans = 0;
unsigned long long L,R;

void input() {
     cin >> L >> R;
}

unsigned long long modpow(ll a, ll m) {
     unsigned long long res = 1;
     while (m>0){
          if(m&1) {
               res = (res * a) % MOD;
          }
          a = (a * a) % MOD;
          m >>= 1;
     }
     return res ;
}

void solve() {
     unsigned long long num = 1;
     for(unsigned long long i=1;i<=19;i++){
          if(num > R) break;
          if((num*10-1) < L){
               num *= 10;continue;
          }
          unsigned long long l = max(num ,L)% MOD;
          unsigned long long r = min(num * 10ULL - 1ULL, R) % MOD;
          unsigned long long nn = ((r-l+1ULL+MOD) * (r+l) ) % MOD;
          ans += ( (nn * modpow(2ULL, MOD - 2ULL) )% MOD) * i % MOD;
          ans %= MOD;
          num *= 10ULL;
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