#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, Q;
vector<ll>A;
vector<vector<ll>>LR;
ll ans = 0;

void input() {
    cin >> N >> Q;
    A.resize(N + 2);
    rep(i, N) {
        cin >> A[i + 1];
    }
    LR.resize(Q + 2, vector<ll>{});
    rep(i, Q) {
        ll l, r, v;cin >> l >> r >> v;
        LR[i + 1] = vector<ll>{ l, r, v };
    }
}

void solve() {
    vector<ll>dif(N + 1);
    for (int i = 1;i < N;i++) {
        dif[i] = A[i + 1] - A[i];
        ans += abs(dif[i]);
    }

    for (int i = 1;i <= Q;i++) {
        int l = LR[i][0], r = LR[i][1], v = LR[i][2];
        ll mae = abs(dif[l - 1]) + abs(dif[r]);
        if (l != 1)dif[l - 1] += v;
        if (r != N)dif[r] -= v;
        ll ato = abs(dif[l - 1]) + abs(dif[r]);
        ans += ato - mae;
        cout << ans << endl;
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}