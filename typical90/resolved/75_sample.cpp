#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
ll prime_sum = 0;
ll ans = 0;

vector<pair<ll, ll>>prime_list(ll n){
    vector<pair<ll, ll>> res;
    for(ll a=2;a*a<=n;a++){
        if(n%a==0){
            ll cnt = 0;
            while(n%a==0){
                n /= a;
                cnt++;
            }
            prime_sum += cnt;
            res.push_back(make_pair(a,cnt));
        }
    }
    if(n!=1LL){
        res.push_back(make_pair(n, 1));
        prime_sum++;
    }
    return res;

}

void input() {
    cin >> N;
}

void solve() {
    auto prime = prime_list(N);
    if(prime.size() == 1 && prime_sum == 1){
        ans = 0;
        return;
    }
    ll cnt = 0;
    ll tmp = 1;
    while(true) {
        if(tmp >= prime_sum) {
            ans = cnt;
            return;
        }
        tmp *= 2;
        cnt++;
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