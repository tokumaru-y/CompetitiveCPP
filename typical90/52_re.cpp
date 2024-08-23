#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<vector<int>> A;
ll ans = 1;
ll MOD = 1000000007;

void input() {
    cin >> N;
    A.resize(N, vector<int>(6));
    rep(i, N)rep(j, 6) {
        cin >> A[i][j];
    }
}

void solve() {
    rep(i, N) {
        ans *= reduce(begin(A[i]), end(A[i]));
        ans %= MOD;
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