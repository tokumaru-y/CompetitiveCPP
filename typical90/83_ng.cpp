#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,M,Q;
vector<int>X,Y;
vector<int>update_small_index,update_large_index;
vector<int>large;
vector<vector<bool>>large_links;
vector<vector<int>>graph;
int B;


void input() {
    cin>> N >> M;
    graph.resize(N,vector<int>());
    rep(i,M){
        int a,b;
        cin >> a >> b;a--;b--;
        graph[a].push_back(b);graph[b].push_back(a);
    }
    B = sqrt(2 * M);
    rep(i,N){
        if(graph[i].size() >= B){
            large.push_back(i);
        }
    }
    large_links.resize(N,vector<bool>(large.size(),false));
    rep(i,large.size()){
        for(int j : graph[large[i]]){
            large_links[j][i] = true;
        }
        large_links[large[i]][i] = true;

    }
    update_small_index.resize(N,-1);
    update_large_index.resize(large.size(),-1);

    cin >> Q;
    X.resize(Q);Y.resize(Q);
    rep(i,Q){
        int x,y;cin >> x >> y;x--;
        X[i] = x;Y[i] = y;
    }
}

void solve() {
    for(int i=0;i<Q;i++){
        int pre = update_small_index[X[i]];
        for(int j=0;j<large.size();j++){
            if(large_links[X[i]][j]) {
                pre = max(pre, update_large_index[j]);
            }
        }

        cout << (pre != -1 ? Y[pre] : 1) << endl;

        if(graph[X[i]].size() < B ) {
            update_small_index[X[i]] = i;
            for(int j=0;j<graph[X[i]].size();j++){
                update_small_index[graph[X[i]][j]] = i;
            }
        } else {
            for(int j=0;j<large.size();j++){
                if(large[j] == X[i]){
                    update_large_index[j] = i;
                    break;
                }
            }
        }
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}