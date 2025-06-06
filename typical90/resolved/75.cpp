#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
int prime_sum = 0;
int ans = 0;

vector<pair<ll, ll>>prime_list(ll n){
    vector<pair<ll, ll>> res;
    for(ll a=2;a*a<=n;a++){
        if(n%a==0){
            int cnt = 0;
            while(n%a==0){
                n /= a;
                cnt++;
            }
            prime_sum += cnt;
            res.push_back(make_pair(a,cnt));
        }
    }
    if(n!=1){
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
    if(prime_sum > 1 && prime_sum%2==1)prime_sum++;
    ans = prime_sum / 2;
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