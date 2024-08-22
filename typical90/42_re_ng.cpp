#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int K;
int MOD = 1000000007;
vector<int>dp;

void input() {
    cin >> K;
    dp.resize(1000100, 0);
}

void solve() {
    dp[0] = 1;
    for (int i = 1;i <= K;i++) {
        int limit = min(i, 9);
        for (int j = 1;j <= limit && i - j >= 0;j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
}

void output() {
    if (K % 9 != 0 || K == 0) {
        cout << 0 << endl;
        return;
    }
    cout << dp[K] << endl;
}

int main()
{
    input();
    solve();
    output();
}