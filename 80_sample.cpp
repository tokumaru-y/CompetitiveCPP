#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,D;
vector<ll>A;
ll ans = 0;

void input() {
    cin >> N >> D;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
    }
}

void solve() {
    for(ll bit = 0;bit< (1<<N);bit++){
        ll conditions = 0;
        ll bit_num = 0;
        for(ll j = 0;j<N;j++){
            if((bit & (1<<j)) > 0 ){
                bit_num |= A[j];
                conditions++;
            }
        }
        ll free_digits = 0;
        for(ll j =0; j<D;j++){
            if((bit_num & (1<<j)) == 0) {
                free_digits++;
            }
        }

        if(conditions % 2 == 0){
            ans += (1LL << free_digits);
        } else {
            ans -= (1LL << free_digits);
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