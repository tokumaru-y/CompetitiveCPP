#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    vector<ll> A(2 * N, 0);
    rep(i, 2 * N)cin >> A[i];
    vector<vector<ll>> dp(2 * N + 1, vector<ll>(2 * N + 1, 0));
    for (int i = 1;i <= 2 * N;i++) {
        for (int j = 1;j <= 2 * N;j++) {
            dp[i][j] = (1 << 29);
        }
        if (i < 2 * N) { dp[i][i + 1] = abs(A[i - 1] - A[i]); }
    }

    for (int i = 3;i <= 2 * N;i += 2) {
        for (int j = 1;j <= 2 * N;j++) {
            int cl = j; int cr = j + i;
            if (cr > 2 * N)continue;
            for (int k = cl;k < 2 * N;k++) {
                dp[cl][cr] = min(dp[cl][cr], dp[cl][k] + dp[k + 1][cr]);
            }
            dp[cl][cr] = min(dp[cl][cr], dp[cl + 1][cr - 1] + abs(A[cl - 1] - A[cr - 1]));
        }
    }

    cout << dp[1][2 * N] << endl;
}