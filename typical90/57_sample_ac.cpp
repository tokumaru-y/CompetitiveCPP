#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> D;
vector<int>S;
int switchNum = 0;

void input() {
    cin >> N >> M;
    D.resize(N, vector<int>(M, 0));
    rep(i, N) {
        int t, x;
        cin >> t;
        rep(j, t) {
            cin >> x;D[i][--x] = 1;
        }
    }
    S.resize(M);
    rep(i, M)cin >> S[i];
}

void solve() {
    rep(panel, M) {
        bool found = false;
        for (int j = switchNum;j < N;j++) {
            if (D[j][panel] == 1) {
                if (j != switchNum) {
                    swap(D[j], D[switchNum]);
                }
                found = true;break;
            }
        }

        if (found) {
            rep(j, N) {
                if (j != switchNum && D[j][panel] == 1) {
                    for (int k = panel;k < M;k++) {
                        D[j][k] ^= D[switchNum][k];
                    }
                }
            }

            if (S[panel] == 1) {
                for (int j = panel;j < M;j++) {
                    S[j] ^= D[switchNum][j];
                }
            }

            switchNum++;
        }
    }
}

void output() {
    if (S == vector<int>(M, 0)) {
        int ans = 1;
        for (int i = switchNum;i < N;i++) {
            ans = ans * 2 % 998244353;
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}