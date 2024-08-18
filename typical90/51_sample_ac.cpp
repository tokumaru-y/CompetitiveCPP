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
    ll mid = N / 2;

    vector<vector<ll>>cnt1(41, vector<ll>());
    for (int bit = 0;bit < (1 << mid); bit++) {
        int choiceCnt = 0;ll costSum = 0;
        for (int i = 0;i < mid;i++) {
            if ((bit & (1 << i)) > 0) {
                costSum += A[i];choiceCnt++;
            }
        }
        cnt1[choiceCnt].push_back(costSum);
    }

    vector<vector<ll>>cnt2(41, vector<ll>());
    for (int bit = 0;bit < (1 << (N - mid)); bit++) {
        int choiceCnt = 0;ll costSum = 0;
        for (int i = 0;i < (N - mid);i++) {
            if ((bit & (1 << i)) > 0) {
                costSum += A[i + mid];choiceCnt++;
            }
        }
        cnt2[choiceCnt].push_back(costSum);
    }


    rep(i, N + 1) {
        sort(cnt1[i].begin(), cnt1[i].end());
        sort(cnt2[i].begin(), cnt2[i].end());
    }

    ll ans = 0;
    for (int h = 0;h <= K;h++) {
        for (int i = 0;i < cnt1[h].size();i++) {
            ll pos = lower_bound(cnt2[K - h].begin(), cnt2[K - h].end(), P - cnt1[h][i] + 1) - cnt2[K - h].begin();
            ans += pos;
        }
    }

    cout << ans << endl;
}