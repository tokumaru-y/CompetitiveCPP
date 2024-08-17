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
    vector<vector<int>> dist(H, vector<int>(W, 1012345678));
    deque<vector<int>> q;
    q.push_front(vector<int>{sx, sy, -1});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        vector<int> t = q.front();q.pop_front();
        int x = t[0];int y = t[1];int pre = t[2];
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];int ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
            if (grid[nx][ny] == '#')continue;

            int nextCnt = dist[x][y];
            if (i != pre && pre != -1)nextCnt++;
            if (nextCnt >= dist[nx][ny])continue;
            dist[nx][ny] = nextCnt;
            if (i != pre) {
                q.push_back(vector<int>{ nx, ny, i});
            }
            else {
                q.push_front(vector<int>{nx, ny, i});
            }
        }
    }

    cout << dist[ex][ey] << endl;
}