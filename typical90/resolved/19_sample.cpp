#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<ll>A;
vector<vector<ll>> dp;
const ll INF = (1LL<<60);

void input() {
    cin >> N;
    N*=2;
    A.resize(N+10,0);
    rep(i,N)cin >> A[i];
    dp.resize(N,vector<ll>(N+10,INF));
}

void solve() {
    // まずは二つの集合の差を計算
    for(int i=0;i<N-1;i++){
        dp[i][i+1]=abs(A[i] - A[i+1]);
    }

    // 4つ以上の要素の集合の計算を行う
    for(int i=3;i<N;i+=2){
        for(int j=0;j<N;j++){
            int left=j;int right=j+i;
            if(right >= N)continue;
            for(int k=left+1;k<right;k++){
                dp[left][right] = min(dp[left][right], dp[left][k] + dp[k+1][right]);
            }
            dp[left][right] = min(dp[left][right], dp[left+1][right-1] + abs(A[left] - A[right]));
        }
    }
}

void output() {
    cout << dp[0][N-1] << endl;
}

int main()
{
    input();
    solve();
    output();
}