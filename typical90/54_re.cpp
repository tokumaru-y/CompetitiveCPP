#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> graph;
vector<int>cnt;

void input() {
    cin >> N >> M;
    graph.resize(N + M, vector<int>());
    cnt.resize(N + M, -1);
    rep(i, M) {
        int k;cin >> k;
        rep(j, k) {
            int r;cin >> r;r--;
            graph[r].push_back(N + i);
            graph[N + i].push_back(r);
        }
    };
}

void solve() {
    cnt[0] = 0;
    deque<int>dq;
    dq.push_back(0);
    while (!dq.empty()) {
        int x = dq.front();dq.pop_front();
        for (int i = 0;i < graph[x].size();i++) {
            int nx = graph[x][i];
            if (cnt[nx] != -1)continue;
            cnt[nx] = cnt[x] + 1;
            dq.push_back(nx);
        }
    }
}

void output() {
    rep(i, N) {
        cout << (cnt[i] == -1 ? cnt[i] : cnt[i] / 2) << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}