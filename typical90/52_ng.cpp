#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
ll ans = 0;ll MOD = 1000000007;
vector<vector<ll>>A;

void dfs(int pos, ll sum) {
    if (pos == N) {
        ans += sum;
        ans %= MOD;
        return;
    }

    rep(i, 6) {
        ll nextSum = sum * A[pos][i] % MOD;
        dfs(pos + 1, nextSum);
    }
}


int main()
{
    cin >> N;
    A.resize(N, vector<ll>(6, 0));
    rep(i, N)rep(j, 6)cin >> A[i][j];

    dfs(0, 1);

    cout << ans << endl;
}