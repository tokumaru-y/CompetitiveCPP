#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    vector<vector<ll>> DCS;
    rep(i, N) {
        ll d, c, s;cin >> d >> c >> s;
        vector<ll> t;
        t.push_back(d);t.push_back(c);t.push_back(s);
        DCS.push_back(t);
    };
    sort(DCS.begin(), DCS.end());

    vector<vector<ll>> dp(5010, vector<ll>(5010, 0));
    rep(i, N) {
        ll d = DCS[i][0];
        ll c = DCS[i][1];
        ll s = DCS[i][2];
        rep(j, 5001) {
            if (j - c + 1 >= 1 && j <= d) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - c] + s);
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    ll ans = 0;
    rep(j, 5001) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << endl;
}