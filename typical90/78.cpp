#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,M;
vector<vector<int>> graph;
int ans =0;

void input() {
    cin >> N >> M;
    graph.resize(N,vector<int>());
    rep(i,M){
        int a,b;cin >> a >> b;
        a--;b--;
        int x = max(a,b);int y = min(a,b);
        graph[x].push_back(b);
    }
}

void solve() {
    rep(i,N){
        int len = graph[i].size();
        if (len == 1)ans++;
    }
}

void output() {
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}