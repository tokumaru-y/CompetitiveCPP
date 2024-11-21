#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int H,W;
vector<vector<bool>>seen;
vector<vector<char>>grid;
int ans = -1;

void input() {
    cin >> H >> W;
    seen.resize(H,vector<bool>(W,false));
    grid.resize(H,vector<char>());
    rep(i,H)rep(j,W){
        char s;cin >> s;
        grid[i].push_back(s);
    }
}

void dfs(int h, int w,int cnt,int fh,int fw) {
    seen[h][w] = true;

    for(int i = 0;i<4;i++){
        int nh = h + dx[i];int nw = w + dy[i];
        if(!(0<=nh && nh < H) || !(0<=nw && nw < W))continue;
        if(nh == fh && nw == fw && cnt >= 3) {
            ans = max(ans, cnt+1);
            continue;
        }
        if(seen[nh][nw] || grid[nh][nw] == '#')continue;
        dfs(nh,nw,cnt + 1,fh,fw);
    }
    seen[h][w] = false;
}

void solve() {
    rep(h,H)rep(w,W){
        if(grid[h][w] == '#')continue;
        dfs(h,w,0,h,w);
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