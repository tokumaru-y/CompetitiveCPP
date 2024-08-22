#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, K;
vector<ll>X;
vector<ll>Y;
vector<vector<ll>>dist;
vector<ll>cost;
vector<vector<ll>> dp;

void input() {
    cin >> N >> K;
    X.resize(N);Y.resize(N);
    dist.resize(N, vector<ll>(N));
    cost.resize(1 << N);
    dp.resize(K + 1, vector<ll>(1 << N, LLONG_MAX));
    rep(i, N) {
        cin >> X[i] >> Y[i];
    }
}

void solve() {
    rep(i, N) {
        for (int j = 0;j < N;j++) {
            ll x = X[i] - X[j];ll y = Y[i] - Y[j];
            dist[i][j] = x * x + y * y;
        }
    }
    for (int bit = 0;bit < (1 << N);bit++) {
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < N;j++) {
                if (i == j)continue;
                if ((bit & (1 << i)) > 0 && (bit & (1 << j)) > 0) {
                    cost[bit] = max(cost[bit], dist[i][j]);
                }
            }
        }
    }


    dp[0][0] = 0;
    for (int k = 0;k < K;k++) {
        for (int bit = 0;bit < (1 << N);bit++) {
            int div_bit = bit;
            while (div_bit != 0) {
                int subDiv = bit ^ div_bit;
                ll tmp = max(dp[k][subDiv], cost[div_bit]);
                dp[k + 1][bit] = min(dp[k + 1][bit], tmp);
                div_bit = (div_bit - 1) & bit;
            }
        }
    }

}

void output() {
    cout << dp[K][(1 << N) - 1] << endl;
}

int main()
{
    input();
    solve();
    output();
}