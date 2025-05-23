#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll K;
ll ans = 0;
ll MOD = 1000000007;

void input() {
    cin >> K;
}

void solve() {
    vector<ll>div{};
    for(ll i=1;i*i<=K;i++){
        if(K % i == 0LL){
            div.push_back(i);
            if(i != K / i) div.push_back(K / i);
        }
    }

    sort(div.begin(), div.end());

    for(int a=0;a<div.size();a++){
        for(int b=a;b<div.size();b++){
            if(div[b] > (K / div[a])) continue;
            if(K % (div[a] * div[b]) != 0LL) continue;
            if(div[b] <= K / (div[a] * div[b]))ans++;
        }
    }
}

void output() {
    cout << ans << endl;
}

int main() {
    input();
    solve();
    output();
}
