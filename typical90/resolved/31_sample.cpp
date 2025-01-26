#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<int> W,B;
// grundy数：ゲームにおいて各盤面のgrundy数が0なら負けの盤面。それ以外の値であれば勝ちの盤面
// grundy数の求め方は、その盤面から移動できるmexの最小値になる。
int grundy[55][1600];

void input() {
    cin >> N;
    rep(i,N){
        int w;cin >> w;
        W.push_back(w);
    }
    rep(i,N){
        int b;cin >> b;
        B.push_back(b);
    }
}

void solve() {
    for(int i=0;i<=50;i++){
        for(int j=0;j<=1560;j++){
            int mex[1570];
            rep(k,1570)mex[k] = 0;
            if(i>=1){
                // なんでこれでよかったんだっけ？
                mex[grundy[i-1][j+i]] = 1;
            }

            if(j>=2){
                for(int k=1;k<=(j/2);k++){
                    mex[grundy[i][j-k]] = 1;
                }
            }

            for(int k=0;k<1570;k++){
                if(mex[k]==0){
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }

    int sum_xor = 0;
    for(int i=0;i<N;i++){
        int t = grundy[W[i]][B[i]];
        sum_xor ^= t;
    }

    if(sum_xor == 0){
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}

void output() {}

int main()
{
    input();
    solve();
    output();
}