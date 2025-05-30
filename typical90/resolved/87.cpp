#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N,P,K;
vector<vector<ll>> A;
ll ans = 0;

void input() {
    cin >> N >> P >> K;
    A.resize(N,vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

ll counted(ll mid, ll k) {
    ll cnt = 0;
    vector<vector<ll>> dp(N, vector<ll>(N, 0));

    rep(i,N)rep(j,N){
        if(A[i][j] == -1) {
            dp[i][j] = mid;
        } else {
            dp[i][j] = A[i][j];
        }
    }

    for(int l=0;l<N;l++){
        for(int n=0;n<N;n++){
            for(int m=0;m<N;m++){
                dp[n][m] = min(dp[n][m], dp[n][l] + dp[l][m]);
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(i == j) continue; // 自分自身への距離は無視
            if(dp[i][j] <= P) {
                cnt++;
            }
        }
    }
    return cnt <= k;// なんでcnt >= k ではなく、cnt <= k なのか？
}

ll check(ll k) {
    // k以下の最小経路のコストは何パターンあるかを返す
    ll ng = 0;ll ok = 10000000000;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2LL;
        bool is_ok  = counted(mid, k);
        if (is_ok) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

void solve() {
    ll cnt1 = check(K);
    ll cnt2 = check(K - 1);
    ans = cnt2 - cnt1;
}

void output() {
    if(ans >= 1000000000 + 1 ){
        cout << "Infinity" << endl;
    } else {
        cout << ans << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}