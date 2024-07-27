#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll INF = INT_MAX;

int main()
{
    int W, N;cin >> W >> N;
    vector<ll>L, R, V;
    rep(i, N) {
        ll l, r, v;cin >> l >> r >> v;
        L.push_back(l);R.push_back(r);V.push_back(v);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
    vector<vector<bool>> is_ok(N + 1, vector<bool>(W + 1, false));
    rep(i, N + 1)is_ok[i][0] = true;
    for (int i = 0;i < N;i++) {
        ll l = L[i];ll r = R[i];ll v = V[i];
        for (int j = 0;j <= W;j++) {
            if (!is_ok[i][j])continue;
            for (ll k = j + l;k <= min((ll)W, j + r);k++) {
                dp[i + 1][k] = max(dp[i][j] + v, dp[i + 1][k]);
                is_ok[i + 1][k] = true;
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            is_ok[i + 1][j] = true;
        }
    }

    ll ans = dp[N][W];
    if (!is_ok[N][W])ans = -1;
    cout << ans << endl;

}