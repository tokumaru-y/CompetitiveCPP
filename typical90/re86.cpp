#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N, Q;
vector<ll> X, Y, Z, W;
ll ans = 1;
ll MOD = 1000000007;

void input() {
    cin >> N >> Q;
    X.resize(Q);
    Y.resize(Q);
    Z.resize(Q);
    W.resize(Q);
    rep(i, Q) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--;
        Y[i]--;
        Z[i]--;
    }
}

void solve() {
    // 60回のビットの探索
    for (int i = 0; i < 60; i++) {
        ll cnt = 0;
        // ビット全探索 (最大2^12通り)
        for (int bit = 0; bit < (1 << N); bit++) {
            bool is_ok = true;
            // Q回の条件をチェック
            rep(k, Q) {
                ll x = X[k], y = Y[k], z = Z[k], w = W[k];
                
                // 3つの要素のいずれかが1ならば、その時のW[k]のiビットが1である必要がある
                if (((bit & (1 << x)) > 0) || ((bit & (1 << y)) > 0) || ((bit & (1 << z)) > 0)) {
                    if ((w & (1 << i)) == 0) {
                        is_ok = false;
                        break;  // このbitに対して条件が満たされないので次のbit探索へ
                    }
                } 
                // 3つの要素が全て0の場合、その時のW[k]のiビットが0である必要がある
                else {
                    if ((w & (1 << i)) > 0) {
                        is_ok = false;
                        break;  // 同上
                    }
                }
            }
            if (is_ok) {
                cnt++;
            }
        }
        // 条件を満たす場合は計算
        ans = (ans * (cnt % MOD)) % MOD;
    }
}

void output() {
    cout << ans << endl;
}

int main() {
    input();
    solve();
    output();
}
