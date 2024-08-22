#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int H, W;
vector<vector<char>> grid;
vector < vector<vector<int>>> cntVec;
int sh, sw, eh, ew;
int ans = 0;

struct Edge {
    int h;
    int w;
    int dict;
};

void input() {
    cin >> H >> W;
    cin >> sh >> sw >> eh >> ew;
    sh--;sw--;eh--;ew--;
    cntVec.resize(H, vector<vector<int>>(W, vector<int>(4, INT_MAX)));
    grid.resize(H, vector<char>(W));
    rep(_h, H)rep(_w, W)cin >> grid[_h][_w];
}

void solve() {
    deque<Edge> dq;
    rep(i, 4) {
        cntVec[sh][sw][i] = 0;
        dq.push_back(Edge{ sh,sw,i });
    }
    while (!dq.empty()) {
        Edge e = dq.front();dq.pop_front();
        for (int i = 0;i < 4;i++) {
            int nh = e.h + dx[i];
            int nw = e.w + dy[i];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W)continue;
            if (grid[nh][nw] == '#')continue;

            if (i == e.dict && cntVec[nh][nw][i] > cntVec[e.h][e.w][e.dict]) {
                cntVec[nh][nw][i] = cntVec[e.h][e.w][e.dict];
                dq.push_front(Edge{ nh,nw,i });
            }
            else if (i != e.dict && cntVec[nh][nw][i] > cntVec[e.h][e.w][e.dict] + 1) {
                cntVec[nh][nw][i] = cntVec[e.h][e.w][e.dict] + 1;
                dq.push_back(Edge{ nh,nw,i });
            }
        }
    }
}

void output() {
    int ans = INT_MAX;
    for (int i = 0;i < 4;i++) {
        ans = min(ans, cntVec[eh][ew][i]);
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}