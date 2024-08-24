#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N, M;
ll C[1 << 19], L[1 << 19], R[1 << 19];


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
    cin >> N >> M;
    for (int i = 1; i <= M;i++) {
        cin >> C[i] >> L[i] >> R[i];
    }

    vector<tuple<ll, int, int>> tup;
    for (int i = 1;i <= M;i++)tup.push_back(make_tuple(C[i], L[i] - 1, R[i]));
    sort(tup.begin(), tup.end());

    ll cnt1 = 0, cnt2 = 0;
    UnionFind uf(N + 2);
    for (int i = 0;i < tup.size();i++) {
        int u = get<1>(tup[i]);
        int v = get<2>(tup[i]);
        if (uf.same(u, v) == false) {
            uf.unite(u, v);
            cnt1 += get<0>(tup[i]);
            cnt2 += 1;
        }
    }


    if (cnt2 != N)cout << -1 << endl;
    else cout << cnt1 << endl;

}