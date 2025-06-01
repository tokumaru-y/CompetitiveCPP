#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N,K;
vector<ll> A,B;
vector<vector<ll>> dp(5010, vector<ll>(5010, 0));
ll ans = 0;

void input() {
    cin >> N >> K;
    A.resize(N);
    B.resize(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
        dp[A[i]][B[i]] += 1;
    }
}

void solve() {
    rep(i, 5000) rep(j, 5000) {
        dp[i][j + 1] += dp[i][j];
    }
    rep(j, 5000) rep(i, 5000) {
        dp[i + 1][j] += dp[i][j];
    }

    for(int a=1;a<=5000;a++){
        for(int b=1;b<=5000;b++){
            ll na = a + K; ll nb = b + K;
            if(na > 5000 || nb > 5000) continue;
            ll tmp = dp[na][nb] - (dp[a-1][nb] + dp[na][b-1] - dp[a-1][b-1]);
            ans = max(ans, tmp);
        }
    }
}

void output() {
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}