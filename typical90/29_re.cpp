#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// ref: https://tsutaj.hatenablog.com/entry/2017/03/30/224339
// 区間に対する更新
// rmq 
using ll = long long;
const int INF = INT_MAX;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
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

    void update(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
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

    int find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};



int main()
{
    int W, N;cin >> W >> N;
    LazySegmentTree tree(vector<ll>(W, 0));
    rep(i, N) {
        int L, R;cin >> L >> R;
        L--;R--;
        ll t = tree.find(L, R + 1);
        tree.update(L, R + 1, t + 1);
        cout << t + 1 << endl;
    }

}