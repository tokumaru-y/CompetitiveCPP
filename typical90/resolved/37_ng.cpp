#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
vector<vector<ll>> dp;
ll W,N;
ll L[510],R[510],V[510];
ll M_INF = -(1L << 60);

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1,M_INF);
        lazy.resize(2 * n - 1, M_INF);
        lazyFlag.resize(2 * n - 1, false);

        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] = lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    // [a,b)
    void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return M_INF;
        if (a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};

void input() {
    cin >> W >> N;
    rep(i,N){
        cin >> L[i] >> R[i] >> V[i];
    }
    dp.resize(N+1,vector<ll>(W+1,M_INF));
}

void solve() {
    rep(i,N+1)dp[i][0] = 0;
    rep(n,N){
        LazySegmentTree tree(dp[n]);
        rep(w,W+1){
            dp[n+1][w] = max(dp[n+1][w], dp[n][w]);
            int left = max(0LL,w - R[n]);int right = max(w - L[n] + 1,0LL);
            if(right == left )continue;
            ll pre_v = tree.find(left, right);
            if(pre_v == M_INF)continue;
            dp[n+1][w] = max(dp[n+1][w], pre_v + V[n]);
        }
    }
}

void output() {
    ll ans = dp[N][W];
    if(ans == M_INF){
        ans = -1;
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}