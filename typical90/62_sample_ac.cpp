#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<vector<int>> graph;
deque<int>dq;
vector<int>colors;
vector<int>ans;

void input() {
    cin >> N;
    colors.resize(N, 0);
    graph.resize(N, vector<int>());
    rep(i, N) {
        int a, b;cin >> a >> b;a--;b--;
        graph[a].push_back(i);
        graph[b].push_back(i);
        if (i == a || i == b) {
            dq.push_back(i);
            colors[i] = 1;
        }
    }
}

void solve() {
    while (!dq.empty()) {
        int x = dq.front();dq.pop_front();
        ans.push_back(x);
        for (int i = 0;i < graph[x].size();i++) {
            int nx = graph[x][i];
            if (nx == x)continue;
            if (colors[nx] == 1)continue;
            dq.push_back(nx);
            colors[nx] = 1;
        }
    }
}

void output() {
    bool isOk = true;
    for (int i = 0;i < N;i++) {
        if (colors[i] != 1)isOk = false;
    }

    if (isOk) {
        reverse(ans.begin(), ans.end());
        rep(i, N) {
            cout << ans[i] + 1 << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}