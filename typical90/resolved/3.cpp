#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<vector<int>> graph;
vector<int>dist;
void bfs(int x){
    deque<pair<int,int>> dq;
    dq.push_back(make_pair(x,0));
    while(!dq.empty()) {
        auto p = dq.front();dq.pop_front();
        int nx = p.first;int cost = p.second;
        for(int y : graph[nx]){
            if(dist[y] != -1)continue;
            dist[y] = cost + 1;
            dq.push_back(make_pair(y,cost+1));
        }
    }
}

void input() {
    cin >> N;
    graph.resize(N,vector<int>{});
    dist.resize(N,-1);
    rep(i,N-1){
        int a,b;cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);graph[b].push_back(a);
    }
}

void solve() {
    dist[0]=0;
    bfs(0);

    int max_i = 0; 
    rep(i,N){
        if(dist[max_i] < dist[i]){
            max_i = i;
        }
    }

    dist.assign(N,-1);
    dist[max_i] = 0;
    bfs(max_i);
}

void output() {
    int ans = 0;
    rep(i,N){
        if(ans < dist[i]){
            ans = dist[i];
        }
    }

    cout << ans + 1 << endl;
}

int main()
{
    input();
    solve();
    output();
}