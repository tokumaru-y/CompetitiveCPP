#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, K;cin >> N >> K;
    int limit = 10000000;
    vector<int> cnt(limit + 10, 0);
    for (int i = 2;i <= limit;i++) {
        if (cnt[i] > 0)continue;
        ll tmp = i;
        while (tmp <= limit) {
            cnt[tmp] += 1;
            tmp += i;
        }
    }

    ll ans = 0;
    for (int i = 2;i <= N;i++) {
        if (cnt[i] >= K)ans++;
    }

    cout << ans << endl;
}