#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

int main()
{
    int N;cin >> N;ll ans = 1;ll MOD = 1000000007;
    rep(i, N) {
        ll tmp = 0;
        rep(j, 6) { ll a;cin >> a;tmp += a; }
        ans *= tmp;ans %= MOD;
    }
    cout << ans << endl;
}