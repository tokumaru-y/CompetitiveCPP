#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll M_INF = -(1LL << 60);
struct SegmentTree {
private:
    int n;
    vector<ll> node;
public:
    SegmentTree(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1;while (n < sz) n *= 2;
        node.resize(2 * n - 1, M_INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for (int i = 0;i < sz;i++)node[i + n - 1] = v[i];
        // for (int i = n - 2;i >= 0;i--)node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, ll val) {
        // 最下段のノードにアクセスする
        x += (n - 1);

        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる
    ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)r = n;
        if (r <= a || b <= l) return M_INF;

        if (a <= l && r <= b)return node[k];

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);

        return max(vl, vr);
    }

};

int main()
{
    int W, N;cin >> W >> N;
    vector<ll>L, R, V;
    rep(i, N) {
        ll l, r, v;cin >> l >> r >> v;
        L.push_back(l);R.push_back(r);V.push_back(v);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
    vector<SegmentTree> trees;

    rep(i, N + 1) {
        rep(j, W + 1) {
            dp[i][j] = M_INF;
        }
        SegmentTree tree(vector<ll>(W + 1, M_INF));
        trees.push_back(tree);
    }
    dp[0][0] = 0;
    trees[0].update(0, 0);

    for (int i = 1;i <= N;i++) {
        ll l = L[i - 1];ll r = R[i - 1];ll v = V[i - 1];
        for (int j = 0;j <= W;j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            int a = max(0LL, j - r);
            int b = max(0LL, j - l + 1);
            if (a == b)continue;
            ll pre_v = trees[i - 1].getmax(a, b);
            if (pre_v == M_INF)continue;
            dp[i][j] = max(dp[i][j], pre_v + v);
        }

        for (int j = 0;j <= W;j++) {
            trees[i].update(j, dp[i][j]);
        }
    }

    if (dp[N][W] == M_INF) {
        cout << -1 << endl;
    }
    else {
        cout << dp[N][W] << endl;
    }

}