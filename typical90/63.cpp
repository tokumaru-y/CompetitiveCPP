#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int H, W;
vector<vector<int>> grid;
int ans = 0;

void input() {
    cin >> H >> W;
    grid.resize(H, vector<int>(W, 0));
    rep(i, H)rep(j, W)cin >> grid[i][j];
}

void solve() {
    for (int bit = 1;bit < (1 << H);bit++) {
        unordered_map<int, int>mp;
        vector<int>usedH;
        rep(i, H) {
            if ((bit & (1 << i)) > 0) {
                usedH.push_back(i);
            }
        }

        for (int w = 0;w < W;w++) {
            bool isOk = true;
            for (int i = 1;i < usedH.size();i++)isOk &= (grid[usedH[i]][w] == grid[usedH[i - 1]][w]);
            if (isOk) {
                mp[grid[usedH[0]][w]] += usedH.size();
            }
        }

        for (auto iter = mp.begin();iter != mp.end();iter++) {
            ans = max(ans, iter->second);
        }
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