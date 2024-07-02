// ref: https://drken1215.hatenablog.com/entry/2021/06/12/181400
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

using Graph = vector<vector<int>>;

vector<int> dfs(const Graph& G, int s) {
    int N = G.size();

    vector<int> dist(N, -1);
    dist[s] = 0;

    stack<int> st({ s });

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        for (auto nv : G[v]) {
            if (dist[nv] == -1) {
                st.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }

    return dist;
}



int main()
{
    int N; cin >> N;
    Graph G(N);
    for (int i = 0;i < N - 1;i++) {
        int a, b;cin >> a >> b;a--, b--;
        G[a].push_back(b);G[b].push_back(a);
    }

    auto dist0 = dfs(G, 0);

    int mx = -1, mv = -1;
    for (int v = 0;v < N;v++) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }


    auto distmv = dfs(G, mv);

    mx = -1;

    for (int v = 0; v < N; v++) {
        if (mx < distmv[v]) {
            mx = distmv[v];
        }
    }

    cout << mx + 1 << endl;
}