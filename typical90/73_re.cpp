#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<char>top_colors;
vector<vector<int>> graph;
vector<vector<ll>>dp;
ll MOD = 1000000007;

void dfs(int x, int parent){
    ll v1 =1;ll v2 = 1;
    if(top_colors[x] == 'a'){
        for(auto nx: graph[x]){
            if(nx == parent)continue;
            dfs(nx,x);
            ll tmp1 = dp[nx][0] + dp[nx][2];
            ll tmp2 = dp[nx][0] + dp[nx][1] + 2*dp[nx][2];
            v1 *= tmp1 % MOD;
            v2 *= tmp2 % MOD;
            v1 %= MOD;v2 %= MOD;
        }
        dp[x][0] = v1;
        dp[x][2] = (v2 - v1 + MOD) % MOD;
    } else {
        for(auto nx: graph[x]){
            if(nx == parent)continue;
            dfs(nx,x);
            ll tmp1 = dp[nx][1] + dp[nx][2];
            ll tmp2 = dp[nx][0] + dp[nx][1] + 2*dp[nx][2];
            v1 *= tmp1 % MOD;
            v2 *= tmp2 % MOD;
            v1 %= MOD;v2 %= MOD;
        }
        dp[x][1] = v1;
        dp[x][2] = (v2 - v1 + MOD)%MOD;
    }
}


void input() {
    cin >> N;
    top_colors.resize(N);
    graph.resize(N,vector<int>());
    dp.resize(N,vector<ll>(3,0));
    rep(i,N){
        cin >> top_colors[i];
    }
    rep(i,N-1){
        int a,b;cin >> a >> b;a--;b--;
        graph[a].push_back(b);graph[b].push_back(a);
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