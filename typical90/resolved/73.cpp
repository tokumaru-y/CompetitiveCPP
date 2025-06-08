#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
vector<char> C;
vector<vector<ll>> graph;
vector<vector<ll>> dp;// dp[i][0]: color a, dp[i][1]: color b, dp[i][2]: color ab

void input() {
    cin >> N;
    C.resize(N);
    rep(i,N)cin >> C[i];
    graph.resize(N, vector<ll>{});
    dp.resize(N, vector<ll>(3, 0));
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int x, int parent){
    ll v1 = 1, v2 = 1;
    for(auto nx: graph[x]){
        if(nx == parent) continue;
        dfs(nx, x);
        if(C[x] == 'a') {
            ll tmp1 = dp[nx][0]  + dp[nx][2];
            ll tmp2 = dp[nx][0] + dp[nx][1] + 2LL * dp[nx][2];
            v1 *= tmp1 % MOD;
            v2 *= tmp2 % MOD;
        } else {
            ll tmp1 = dp[nx][1] + dp[nx][2];
            ll tmp2 = dp[nx][0] + dp[nx][1] + 2LL * dp[nx][2];
            v1 *= tmp1 % MOD;
            v2 *= tmp2 % MOD;
        }
        v1 %= MOD;
        v2 %= MOD;
    }

    if(C[x] == 'a') {
        dp[x][0] = v1;
        dp[x][2] = (v2 - v1 + MOD) % MOD;
    } else if (C[x] == 'b') {
        dp[x][1] = v1;
        dp[x][2] = (v2 - v1 + MOD) % MOD;
    }
}

void solve() {
    dfs(0,-1);
}

void output() {
    cout << dp[0][2] << endl;
}

int main()
{
    input();
    solve();
    output();
}