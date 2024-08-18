#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;


int main()
{
    int N, L;cin >> N >> L;
    ll max = 100000;
    vector<ll> dp(max + 10, 0);
    dp[0] = 1;
    for (int i = 1;i <= max;i++) {
        dp[i] += dp[i - 1];
        if (i - L >= 0)dp[i] += dp[i - L];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;
}