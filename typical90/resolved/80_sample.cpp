#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N,D;
vector<ll> A;
ll ans = 0;

void input() {
    cin >> N >> D;
    A.resize(N);
    rep(i, N) cin >> A[i];  
}

void solve() {
    for(int bit = 0; bit < (1<<N); bit++){
        ll condition = 0;
        ll bit_sum = 0;
        for(int i=0;i<N;i++){
            if((bit & (1LL<<i)) > 0){
                bit_sum |= A[i];
                condition += 1;
            }
        }

        ll free_cnt = 0;
        for(int i=0;i<D;i++){
            if((bit_sum & (1LL<<i)) == 0){
                free_cnt++;
            }
        }

        if(condition % 2 == 0 ){
            ans += (1LL << free_cnt);
        } else {
            ans -= (1LL << free_cnt);
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