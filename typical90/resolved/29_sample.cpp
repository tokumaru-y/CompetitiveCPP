#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

struct LazySegmentTree {
private:
    int n;

public:
    vector<ll> node, lazy;
    vector<bool> lazyFlag;
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
        lazy.resize(2 * n - 1, 0);
        lazyFlag.resize(2 * n - 1, false);


        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = max(node[i * 2 + 1],node[i * 2 + 2]);
    }

    // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

        // 遅延配列が空でない場合、自ノード及び子ノードへの
        // 値の伝播が起こる
        if (lazyFlag[k]) {
            node[k] = lazy[k];

            // 最下段かどうかのチェック
            if (r - l > 1) {
                lazy[2 * k + 1] = lazy[k];
                lazy[2 * k + 2] = lazy[k];
                lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
            }

            // 伝播が終わったので、自ノードの遅延配列を空にする
            lazyFlag[k] = false;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;

        // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

        // 範囲外なら何もしない
        if (b <= l || r <= a) return;

        // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k]=true;
            eval(k, l, r);
        }
        // そうでないならば、子ノードの値を再帰的に計算して、
        // 計算済みの値をもらってくる
        else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll getvalue(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return 0;

        // 関数が呼び出されたら評価！
        eval(k, l, r);
        if (a <= l && r <= b) return node[k];
        ll vl = getvalue(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getvalue(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl,vr);
    }
};
int W,N;
vector<vector<ll>> LR;

void input() {
    cin >> W >> N;
    rep(i,N){
        ll l,r;cin >> l >> r;
        l--;r--;
        LR.push_back(vector<ll>{l,r});
    }
}

void solve() {
    auto tree = LazySegmentTree(vector<ll>(W,0));
    rep(i,N){
        ll l = LR[i][0];ll r = LR[i][1];
        ll t = tree.getvalue(l,r+1);
        tree.add(l,r+1,t+1);
        cout << tree.getvalue(l,r+1) << endl;
    }
}

void output() {
}

int main()
{
    input();
    solve();
    output();
}