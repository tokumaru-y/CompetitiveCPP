#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, K;cin >> N >> K;
    vector<int> cnt(1 << 24, 0);
    for (int i = 2;i <= N;i++) {
        if (cnt[i] >= 1)continue;
        for (int j = i;j <= N;j += i) cnt[j] += 1;
    }
    int ans = 0;
    for (int i = 1;i <= N;i++) {
        if (cnt[i] >= K)ans += 1;
    }
    cout << ans << endl;

}