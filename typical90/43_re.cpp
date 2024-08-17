#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

int main()
{
    int H, W;cin >> H >> W;
    int sx, sy, ex, ey;cin >> sx >> sy >> ex >> ey;
    sx--;sy--;ex--;ey--;
    vector<vector<char>> grid(H, vector<char>(W));
    rep(i, H)rep(j, W) {
        cin >> grid[i][j];
    }
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, 1000000000)));
    deque<vector<int>> q;
    rep(i, 4) {
        q.push_front({ sx, sy, i });
        dist[sx][sy][i] = 0;
    }
    while (!q.empty()) {
        vector<int> t = q.front();q.pop_front();
        int x = t[0];int y = t[1];int pre = t[2];
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];int ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
            if (grid[nx][ny] == '#')continue;

            int nextCnt = dist[x][y][pre] + (i != pre ? 1 : 0);
            if (dist[nx][ny][i] > nextCnt) {
                dist[nx][ny][i] = nextCnt;
                // なぜこの条件分岐が必要かは、この記事がわかり易い。https://betrue12.hateblo.jp/entry/2018/12/08/000020
                if (i != pre)q.push_back({ nx,ny,i });
                else q.push_front({ nx,ny,i });
            }
        }
    }
    int ans = 10000000;
    rep(i, 4) {
        ans = min(ans, dist[ex][ey][i]);
    }

    cout << ans << endl;
}