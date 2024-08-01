#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int W[100010], B[100010];
int grundy[55][2000];

void calc() {
    for (int i = 0;i <= 50;i++) {
        for (int j = 0;j <= 1500;j++) {
            bool mex[2000];
            rep(k, 2000)mex[k] = false;
            if (i >= 1) {
                mex[grundy[i - 1][j + i]] = true;
            }
            if (j >= 2) {
                for (int k = 1;k <= (j / 2);k++) {
                    mex[grundy[i][j - k]] = true;
                }
            }

            for (int k = 0;k < 2000;k++) {
                if (!mex[k]) { grundy[i][j] = k;break; }
            }
        }
    }
}


int main()
{
    int N;cin >> N;
    rep(i, N) {
        cin >> W[i];
    }
    rep(i, N) {
        cin >> B[i];
    }

    calc();

    int sum_xor = 0;
    rep(i, N) {
        sum_xor ^= grundy[W[i]][B[i]];
    }

    if (sum_xor == 0) {
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }

}