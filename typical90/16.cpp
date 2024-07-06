#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N; cin >> N;int A, B, C; cin >> A >> B >> C;
    ll ans = (1LL << 60);
    for (ll i = 0; i < 10000;i++) {
        for (ll j = 0;j < 10000;j++) {
            ll tmp_sum = i * A + j * B;
            if (tmp_sum > N || (N - tmp_sum) % C != 0) { continue; }
            ll les = (N - tmp_sum) / C;
            ans = min(ans, i + j + les);
        }
    }

    cout << ans << endl;
}