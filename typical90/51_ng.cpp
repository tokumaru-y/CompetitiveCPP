#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

int main()
{
    ll N, K, P;cin >> N >> K >> P;
    vector<ll> A(N);rep(i, N)cin >> A[i];
    ll maxNum = (1LL << 62) - 1;
    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, maxNum));

    dp[0][0] = 0;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j <= K;j++) {
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
            if (j - 1 >= 0 && dp[i][j - 1] != maxNum) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1] + A[i]);
            }
        }
    }

    ll ans = 0;
    rep(i, K + 1) {
        if (dp[N][i] <= P)ans++;
    }

    cout << ans << endl;
}