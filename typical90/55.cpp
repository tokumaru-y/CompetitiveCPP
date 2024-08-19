#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<ll> A;
ll P, Q;
ll ans = 0;

void input() {
    cin >> N >> P >> Q;
    rep(i, N) {
        ll t;cin >> t;A.push_back(t);
    }
}

void dfs(ll sum, int index, int cnt) {
    if (cnt == 5) {
        if (sum % P == Q)ans++;
        return;
    }
    for (int i = index + 1;i < (N - (5 - cnt - 1)); i++) {
        ll nextSum = (sum * A[i]) % P;
        dfs(nextSum, i, cnt + 1);
    }
}

void solve() {
    for (int i = 0;i < (N - 4);i++) {
        dfs(A[i], i, 1);
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