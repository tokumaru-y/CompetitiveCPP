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
    for(int i=0;i<N;i++){
        for(int j=i+1 ;j<N;j++){
            if((j-i) % 2 ==0)continue;
            if(j - i == 1){
                dp[i][j] = min(abs(A[i] - A[j]), dp[i][j]);
            } else if ((j-i) == 3) {
                dp[i][j] = min(dp[i][j], min(dp[i+1][j-1] + abs(A[i] - A[j]), abs(A[i] - A[i+1]) + abs(A[j] - A[j-1])) );
            } else {
                dp[i][j] = min(
                    dp[i][j],
                    min(dp[i+1][j-1] + abs(A[i] - A[j]),
                    abs(A[j] - A[j-1]) + abs(A[i] - A[i+1]) + dp[i+2][j-2] )
                    );
            }
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