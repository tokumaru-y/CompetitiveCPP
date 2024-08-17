#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll ans = 0;
ll MOD = 1000000007;


int main()
{
    int K;cin >> K;
    if (K < 9 || K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int>dp(1000100, 0);
    dp[0] = 1;
    for (int i = 1;i <= K;i++) {
        int l = min(i, 9);
        for (int j = 1;j <= l && i - j >= 0;j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[K] << endl;
}