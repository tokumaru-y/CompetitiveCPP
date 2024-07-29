#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<ll> dp;

void dfs(int v, int pre, vector<vector<int>> graph) {
    dp[v] = 1;
    for (auto nv : graph[v]) {
        if (nv == pre)continue;
        dfs(nv, v, graph);
        dp[v] += dp[nv];
    }
}


int main()
{
    int N;cin >> N;vector<vector<int>> graph(N, vector<int>());
    vector<int> A(N);vector<int>B(N);
    rep(i, N - 1) {
        int a, b;cin >> a >> b;a--;b--;
        graph[a].push_back(b);graph[b].push_back(a);
        A[i] = a;B[i] = b;
    }
    dp.resize(N, 0);
    dfs(0, -1, graph);
    ll ans = 0;
    for (int i = 0;i < N - 1;i++) {
        ll r = min(dp[A[i]], dp[B[i]]);
        // ll r = dp[A[i]];
        ans += r * (N - r);
    }

    cout << ans << endl;
}