//ref: https://tsutaj.hatenablog.com/entry/2017/03/29/204841
// RMQ
int const INF = INT_MAX;
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
        node.resize(2 * n - 1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for (int i = 0;i < sz;i++)node[i + n - 1] = v[i];
        for (int i = n - 2;i >= 0;i--)node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, ll val) {
        // 最下段のノードにアクセスする
        x += (n - 1);

        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる
    int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)r = n;
        if (r <= a || b <= l) return INF;

        if (a <= l && r <= b)return node[k];

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        ll vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);

        return min(vl, vr);
    }

};

// RSQ
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
        node.resize(2 * n - 1, 0);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for (int i = 0;i < sz;i++)node[i + n - 1] = v[i];
        for (int i = n - 2;i >= 0;i--)node[i] = (node[2 * i + 1] + node[2 * i + 2]);
    }

    void update(int x, ll val) {
        // 最下段のノードにアクセスする
        x += (n - 1);

        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2 * x + 1] + node[2 * x + 2]);
        }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる
    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)r = n;
        if (r <= a || b <= l) return 0;

        if (a <= l && r <= b)return node[k];

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);

        return (vl + vr);
    }

};