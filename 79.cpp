#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, 1, 0};
vector<int> dy{ 0, 1, 1, 0};
int H,W;
vector<vector<int>> graphA;
vector<vector<int>> graphB;
ll ans = 0;

void input() {
    cin >> H >> W;
    graphA.resize(H,vector<int>(W,0));
    graphB.resize(H,vector<int>(W,0));
    rep(i,H)rep(j,W)cin >> graphA[i][j];
    rep(i,H)rep(j,W)cin >> graphB[i][j];
}

void solve() {
    rep(i,H-1)rep(j,W-1){
        ll dif = graphB[i][j] - graphA[i][j];
        ans += abs(dif);
        rep(k,4){
            int nh = i + dx[k];int nw = j + dy[k];
            graphA[nh][nw] += dif;
        }
    }
}

void output() {
    rep(i,H)rep(j,W){
        if(graphA[i][j] != graphB[i][j]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}