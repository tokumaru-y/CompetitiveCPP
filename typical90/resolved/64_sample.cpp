#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
int N,Q;
vector<ll> A;
vector<ll> dif;
ll ans = 0;

void input() {
    cin >> N >> Q;
    A.resize(N+1);
    dif.resize(N+2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N; i++) {
        dif[i] = A[i + 1] - A[i];
        ans += abs(A[i + 1] - A[i]);
    }
}

void solve() {
    rep(i,Q){
        ll l, r, v;
        cin >> l >> r >> v;
        ll before = abs(dif[l-1]) + abs(dif[r]);
        if(l > 1)dif[l-1] += v;
        if(r < N)dif[r] -= v;
        ll after = abs(dif[l-1]) + abs(dif[r]);
        ans += after - before;
        cout << ans << endl;
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}