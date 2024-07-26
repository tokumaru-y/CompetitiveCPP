#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int dx[8] = { -1, -1,-1, 0, 1, 1,1,0 };
int dy[8] = { -1, 0, 1, 1,1,0,-1,-1 };

int main()
{
    int H, W;cin >> H >> W;
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    if (H == 1 || W == 1) {
        cout << H * W << endl;
        return 0;
    }
    int ans = 0;
    rep(i, H)rep(j, W) {
        int nh;int nw;bool is_ok = true;
        rep(x, 8) {
            nh = i + dx[x];nw = j + dy[x];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W)continue;
            if (grid[nh][nw] == true)is_ok = false;
        }
        if (is_ok) {
            grid[i][j] = true;
            ans++;
        }
    }

    cout << ans << endl;
}