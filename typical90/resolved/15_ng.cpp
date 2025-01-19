#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void input() {
    cin >> N;
    COMinit();
}

ll query(int k){
    long long ret = 0;
	for (int i = 1; i <= N / k + 1; i++) {
		int s1 = N - (k - 1) * (i - 1);
		int s2 = i;
		ret += COM(s1, s2);
		ret %= MOD;
	}
	return ret;
}

void solve() {
    for(int k=1;k<=N;k++){
        ll ans = query(k);
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