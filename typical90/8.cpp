#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll MOD = 1000000007;

int main()
{
    int N;cin >> N;
    string S;cin >> S;
    vector<vector<ll>> dp(N + 10, vector<ll>(7, 0));
    vector<char> target_char = { 'a','t', 'c', 'o', 'd', 'e', 'r' };
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < 7;j++) {
            if (j == 0) {
                dp[i + 1][j] = dp[i][j];
                if (S[i] == target_char[j]) dp[i + 1][j]++;
            }
            else {
                dp[i + 1][j] = dp[i][j];
                if (S[i] == target_char[j]) {
                    dp[i + 1][j] += dp[i][j - 1];
                }
            }
            dp[i][j] %= MOD;
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[N][6] % MOD << endl;
}