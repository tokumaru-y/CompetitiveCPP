#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge {
    int to;
    int cost;
};
int const INF = INT_MAX;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<ll> dist0(1 << 20, INF);
vector<ll> dist1(1 << 20, INF);
vector<vector<Edge>> graph;

void dfs0() {
    priority_queue<P, vector<P>> que;
    dist0[0] = 0;
    que.push(make_pair(0, 0));

    while (que.size() > 0) {
        P tmp = que.top();
        que.pop();
        for (auto e : graph[tmp.second]) {
            if (dist0[e.to] > dist0[tmp.second] + e.cost) {
                dist0[e.to] = dist0[tmp.second] + e.cost;
                que.push(make_pair(e.cost, e.to));
            }
        }
    }
}

void dfs1(int n) {
    priority_queue<P, vector<P>> que;
    dist1[n] = 0;
    que.push(make_pair(0, n));

    while (que.size() > 0) {
        P tmp = que.top();
        que.pop();
        for (auto e : graph[tmp.second]) {
            if (dist1[e.to] > dist1[tmp.second] + e.cost) {
                dist1[e.to] = dist1[tmp.second] + e.cost;
                que.push(make_pair(e.cost, e.to));
            }
        }
    }
}

int main()
{
    int N, M;cin >> N >> M;
    graph.resize(N + 10, vector<Edge>());
    rep(i, M) {
        int a, b, c;cin >> a >> b >> c;a--;b--;
        graph[a].push_back(Edge{ b,c });graph[b].push_back(Edge{ a,c });
    }

    dfs0();
    dfs1(N - 1);

    rep(i, N) {
        cout << dist0[i] + dist1[i] << endl;
    }
}