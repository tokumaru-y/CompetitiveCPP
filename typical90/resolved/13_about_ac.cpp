#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,M;
vector<vector<pair<int,ll>>> graph;
vector<ll> dist1;
vector<ll> dist2;
const ll INF = (1LL<<60);

void input() {
    cin >> N >> M;
    graph.resize(N,vector<pair<int,ll>>());
    dist1.resize(N,INF);
    dist2.resize(N,INF);
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back(make_pair(b,c));graph[b].push_back(make_pair(a,c));
    }
}

void solve() {
    dist1[0]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> dq;dq.push(make_pair(0,0));
    while(!dq.empty()){
        auto x = dq.top();dq.pop();
        if(dist1[x.second] < x.first)continue;
        for(auto nx : graph[x.second]) {
            ll distance = nx.second + x.first;
            if(dist1[nx.first] <= distance)continue;
            dist1[nx.first] = distance;
            dq.push(make_pair(distance,nx.first));
        }
    }

    dist2[N-1]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> dq2;dq2.push(make_pair(0,N-1));
    while(!dq2.empty()){
        auto x = dq2.top();dq2.pop();
        if(dist2[x.second] < x.first)continue;
        for(auto nx : graph[x.second]) {
            ll distance = nx.second + x.first;
            if(dist2[nx.first] <= distance)continue;
            dist2[nx.first] = distance;
            dq2.push(make_pair(dist2[nx.first],nx.first));
        }
    }
}

void output() {
    rep(i,N){
        cout << dist1[i] + dist2[i] << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}