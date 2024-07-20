#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for (int i = 0;i < N;i++)par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
int main()
{
    int H, W;cin >> H >> W;int Q;cin >> Q;
    UnionFind uf(H * W + W);
    vector<vector<bool>> reds(H, vector<bool>(W, false));
    rep(i, Q) {
        int q;cin >> q;
        if (q == 1) {
            int r, c;cin >> r >> c;r--;c--;
            reds[r][c] = true;
            for (int i = 0;i < 4;i++) {
                int nh = dx[i] + r;int nw = dy[i] + c;
                if (0 > nh || nh >= H || nw < 0 || nw >= W)continue;
                if (reds[nh][nw] == false) continue;
                ll n = nh * W + nw;
                uf.unite(n, r * W + c);
            }
        }
        else {
            int a, b, c, d;cin >> a >> b >> c >> d;a--;b--;c--;d--;
            if (uf.same(a * W + b, c * W + d) && reds[a][b] && reds[c][d]) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}