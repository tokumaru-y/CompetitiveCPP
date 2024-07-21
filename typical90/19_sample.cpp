#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    int A[500];
    rep(i, 2 * N) {
        int a;cin >> a;A[i + 1] = a;
    }
    vector<vector<int>> dp(2 * N + 2, vector<int>(2 * N + 2, 0));
    for (int i = 1;i <= 2 * N;i++) {
        for (int j = i;j <= 2 * N;j++)dp[i][j] = (1 << 29);
        if (i < 2 * N)dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }

    for (int i = 3;i <= 2 * N;i += 2) {
        for (int j = 1;j <= 2 * N - 1;j++) {
            int cl = j, cr = j + i;
            if (cr > 2 * N)continue;
            for (int k = cl;k <= cr - 1;k++)dp[cl][cr] = min(dp[cl][cr], dp[cl][k] + dp[k + 1][cr]);
            dp[cl][cr] = min(dp[cl][cr], dp[cl + 1][cr - 1] + abs(A[cl] - A[cr]));
        }
    }

    cout << dp[1][2 * N] << endl;
}