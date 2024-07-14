#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    vector<vector<int>> dp(1010, vector<int>(1010, 0));
    rep(i, N) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        dp[a][b] += 1;dp[c][b] -= 1;
        dp[a][d] -= 1;dp[c][d] += 1;
    }

    rep(i, 1001) {
        rep(j, 1001) {
            dp[i][j + 1] += dp[i][j];
        }
    }
    rep(j, 1001) {
        rep(i, 1001) {
            dp[i + 1][j] += dp[i][j];
        }
    }
    vector<int> ans(N + 1, 0);
    rep(i, 1001)rep(j, 1001) {
        if (dp[i][j] > 0)ans[dp[i][j]]++;
    }

    rep(i, N) {
        cout << ans[i + 1] << endl;
    }

}