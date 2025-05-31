#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll K;
ll ans = 0;

void input() {
    cin >> K;
}

vector<ll> get_list() {
    vector<ll> div_list;
    for (ll i = 1; i * i <= K; i++) {
        if (K % i == 0) {
            div_list.push_back(i);
            if (i != K / i) {
                div_list.push_back(K / i);
            }
        }
    }
    sort(div_list.begin(), div_list.end());
    return div_list;
}

void solve() {
    vector<ll> div_list = get_list();
    ll n = div_list.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ll a = div_list[i];
            ll b = div_list[j];
            if((K / a) % b == 0){
                ll c = K / a / b;
                if(c >= b){
                    ans++;
                }
            }
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