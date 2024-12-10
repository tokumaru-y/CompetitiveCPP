#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,Q;
vector<ll> A;
vector<vector<bool>>XY;

void input() {
    cin >> N >> Q;
    A.resize(N);XY.resize(N,vector<bool>(N,true));
    rep(i,N)cin >> A[i];
    rep(i,Q){
        int x,y;
        cin >> x >> y;--x;--y;
        XY[x][y]=false;XY[y][x]=false;
    }
}


void output(vector<int> a, vector<int> b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << a.size() << endl;
    rep(i,a.size()){
        if(i == a.size()-1){
            cout << a[i]+1 << endl;
        } else {
            cout << a[i]+1 << " ";
        }
    }
    cout << b.size() << endl;
    rep(i,b.size()){
        if(i == b.size()-1){
            cout << b[i]+1 << endl;
        } else {
            cout << b[i]+1 << " ";
        }
    }

    exit(0);
}

void solve() {
    vector<vector<int>>dp(9000,vector<int>{-1});
    dp[0] = vector<int>{};
    for(int i=0;i<N;i++){
        for(int j=8888;j>=0;j--){
            if(dp[j].size() == 0){
                if(dp[j+A[i]][0] != -1){
                    output(dp[j+A[i]],vector<int>{i});
                }
                dp[j+A[i]] = vector<int>{i};
            }
            else if(dp[j][0] != -1){
                if(j+A[i] > 8888)continue; //おそらく通らない
                bool is_ok = true;
                for(int k=0;k<dp[j].size();k++){
                    int ind = dp[j][k];
                    is_ok &= XY[ind][i];
                }
                if(!is_ok)continue;
                if(dp[j+A[i]][0] != -1){
                    dp[j].push_back(i);
                    output(dp[j+A[i]],dp[j]);
                } else {
                    vector<int> tmp{};
                    rep(l,dp[j].size())tmp.push_back(dp[j][l]);
                    tmp.push_back(i);
                    dp[j+A[i]] = tmp;
                }
            }
        }
    }
}


int main()
{
    input();
    solve();
}