#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> graph;
vector<int>ans;


void input() {
    cin >> N >> M;
    graph.resize(N + M, vector<int>());
    ans.resize(N + M, -2);
    rep(i, M) {
        int K;cin >> K;
        rep(j, K) {
            int t;cin >> t;t--;
            graph[N + i].push_back(t);
            graph[t].push_back(N + i);
        }
    }
}

void solve() {
    deque<int>dq;
    dq.push_back(0);
    ans[0] = 0;
    while (!dq.empty()) {
        int nx = dq.front();dq.pop_front();
        for (int i = 0;i < graph[nx].size();i++) {
            int top = graph[nx][i];
            if (ans[top] != -2)continue;
            ans[top] = ans[nx] + 1;
            dq.push_back(top);
        }
    }
}

void output() {
    rep(i, N) {
        cout << ans[i] / 2 << endl;
    }
}



int main()
{
    input();

    solve();

    output();
}