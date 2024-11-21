#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<bool>is_a_position;
vector<vector<int>>graph;
ll cnt = 0;
ll MOD = 1000000007;
vector<bool>seen;

struct Data {
    int pos;
    int a_cnt;
    int b_cnt;
};

void input() {
    cin >> N;
    graph.resize(N,vector<int>());
    seen.resize(N,false);
    rep(i,N){
        char s;cin >> s;
        if(s == 'b'){
            is_a_position.push_back(false);
        } else {
            is_a_position.push_back(true);
        }
    }
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(Data d) {
    seen[d.pos]=true;
    for(int nx : graph[d.pos]){
        if(seen[nx])continue;
        if(is_a_position[nx]){
            d.a_cnt+=1;
        } else {
            d.b_cnt+=1;
        }

        if(d.a_cnt == d.b_cnt) {
            cnt += 1;
            d.a_cnt = 0;d.b_cnt = 0;
        }
        d.pos = nx;
        dfs(d);
    }
}

void solve() {
    Data d = {0,0,0};
    if(is_a_position[0]) {
        d.a_cnt+=1;
    } else {
        d.b_cnt+=1;
    }
    dfs(d);
}

void output() {
    if(cnt == 0){
        cout << 0 << endl;
    } else {
        ll ans = 1;
        rep(i,cnt-1){
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}