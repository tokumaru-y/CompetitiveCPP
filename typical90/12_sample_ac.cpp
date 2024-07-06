#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    int H, W;cin >> H >> W;
    int Q;cin >> Q;
    UnionFind uf(H * W + W);
    vector<vector<bool>> used(H + 10, vector<bool>(W + 10, false));
    while (Q > 0) {
        Q--;
        int q;cin >> q;
        if (q == 1) {
            int r, c;cin >> r >> c;
            r--;c--;
            used[r][c] = true;
            int dx[4] = { -1, 0, 1, 0 };
            int dy[4] = { 0, 1, 0, -1 };
            int h = (r * W) + c;
            for (int i = 0; i < 4; i++) {
                int sx = r + dx[i], sy = c + dy[i];
                if (sx < 0 || sx > H || sy < 0 || sy > W || used[sx][sy] == false)continue;
                int hash1 = (sx * W) + sy;
                uf.unite(h, hash1);
            }
            used[r][c] = true;
        }
        else {
            int r, a, rr, aa;cin >> r >> a >> rr >> aa;r--;a--;rr--;aa--;
            if (used[r][a] == false && used[rr][aa] == false) { cout << "NO" << endl; continue; }
            int hash1 = r * W + a;int hash2 = rr * W + aa;
            if (uf.same(hash1, hash2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}