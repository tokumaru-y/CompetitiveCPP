#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll MAX_INF = 1000000000000000000;

// ref: https://zenn.dev/hossy3/books/rust-typical90/viewer/typical90_045#%E3%81%99%E3%81%B9%E3%81%A6%E3%81%AE%E3%82%B0%E3%83%AB%E3%83%BC%E3%83%97%E5%80%99%E8%A3%9C%E3%81%AE%E8%B7%9D%E9%9B%A2%E6%9C%80%E5%A4%A7%E5%80%A4%E3%82%92%E6%B1%82%E3%82%81%E3%82%8B
int main()
{
    int N, K;cin >> N >> K;
    vector<ll>X, Y;
    rep(i, N) {
        ll x, y;cin >> x >> y;
        X.push_back(x);Y.push_back(y);
    }
    vector<vector<ll>> dist(N, vector<ll>(N));
    rep(i, N)rep(j, N) {
        if (i == j)continue;
        ll xx = (X[i] - X[j]);ll yy = (Y[i] - Y[j]);
        dist[i][j] = xx * xx + yy * yy;
    }

    vector<ll> cost((1 << N));
    for (int bit = 0; bit < (1 << N);bit++) {
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < N;j++) {
                if (bit & (1 << i) && bit & (1 << j)) {
                    cost[bit] = max(cost[bit], dist[i][j]);
                }
            }
        }
    }

    vector<vector<ll>> dp(K + 1, vector<ll>(1 << N, MAX_INF));
    dp[0][0] = 0;
    for (int k = 0;k < K;k++) {
        for (int bit = 0;bit < (1 << N);bit++) {
            int div_bit = bit;
            while (div_bit != 0) {
                int div_bit2 = bit ^ div_bit;
                // ここはdivbit2,divbitはチェンジしてはいけない。今の条件ではdivbit0の時に処理が進まないため.
                // そのため、whileの条件を変更し処理が進むようにすればOK
                ll x = max(dp[k][div_bit2], cost[div_bit]);
                dp[k + 1][bit] = min(dp[k + 1][bit], x);
                div_bit = (div_bit - 1) & bit;
            }
        }
    }

    cout << dp[K][(1 << N) - 1] << endl;
}