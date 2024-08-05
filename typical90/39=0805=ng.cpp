#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dp;

void dfs(int x, int pre, vector<vector<int>>& graph) {
    dp[x] = 1;
    for (auto nx : graph[x]) {
        if (nx == pre)continue;
        dfs(nx, x, graph);
        dp[x] += dp[nx];
    }
}


int main()
{
    int N;cin >> N;
    vector<vector<int>> graph(N, vector<int>());
    dp.resize(N, 0);vector<int> A(N - 1);vector<int>B(N - 1);
    rep(i, N - 1) {
        int a, b;cin >> a >> b;a--;b--;
        graph[a].push_back(b);graph[b].push_back(a);
        A[i] = a;B[i] = b;
    }
    dfs(0, -1, graph);

    ll ans = 0;
    for (int i = 0;i < N - 1;i++) {
        ll x = min(dp[A[i]], dp[B[i]]);
        ans += x * (N - x);
    }

    cout << ans << endl;
}