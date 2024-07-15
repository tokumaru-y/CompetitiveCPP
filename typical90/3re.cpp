#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


vector<int> dfs(vector<vector<int>> graph, int v) {
    vector<int> res(graph.size(), -1);
    stack<int> s;
    s.push(v);
    res[v] = 0;
    while (!s.empty()) {
        int nv = s.top();
        s.pop();
        for (auto g : graph[nv]) {
            if (res[g] != -1)continue;
            res[g] = res[nv] + 1;
            s.push(g);
        }
    }

    return res;
}

int main()
{
    int N;cin >> N;
    vector<vector<int>> graph(N, vector<int>());
    rep(i, N - 1) {
        int A, B;cin >> A >> B;
        A--;B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<int> dist0 = dfs(graph, 0);
    int nv = -1;int nx = -1;

    rep(i, N) {
        if (nx < dist0[i]) {
            nx = dist0[i];
            nv = i;
        }
    }

    vector<int> dist1 = dfs(graph, nv);

    int ans = -1;
    rep(i, N) {
        if (ans < dist1[i]) {
            ans = dist1[i];
        }
    }

    cout << ans + 1 << endl;

}