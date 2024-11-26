#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,K;
vector<vector<int>>dp(5010,vector<int>(5010,0));
vector<int>A;
vector<int>B;
int ans = 0;
void input() {
    cin >> N >> K;
    A.resize(N);B.resize(N);
    rep(i,N){
        cin >> A[i] >> B[i];
        dp[A[i]][B[i]] += 1;
    }
}

void solve() {
    rep(i,5000)rep(j,5000){
        dp[i][j+1] += dp[i][j];
    }
    rep(j,5000)rep(i,5000){
        dp[i+1][j] += dp[i][j];
    }
    
    for(int a = 1;a<=5000;a++){
        for(int b=1; b<=5000;b++){
            int na = a + K;int nb = b + K;
            if(na > 5000 || nb > 5000)continue;
            int tmp = dp[na][nb] - (dp[a-1][nb] + dp[na][b-1] - dp[a-1][b-1]);
            ans = max(ans, tmp);
        }
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