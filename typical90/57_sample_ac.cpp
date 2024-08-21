#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> D;
vector<int>S;
int pos = 0;

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
    rep(i, M) {
        bool found = false;
        for (int j = pos;j < N;j++) {
            if (D[j][i] == 1) {
                if (j != pos) {
                    swap(D[j], D[pos]);
                }
                found = true;break;
            }
        }

        if (found) {
            rep(j, N) {
                if (j != pos && D[j][i] == 1) {
                    for (int k = i;k < M;k++) {
                        D[j][k] ^= D[pos][k];
                    }
                }
            }

            if (S[i] == 1) {
                for (int j = i;j < M;j++) {
                    S[j] ^= D[pos][j];
                }
            }

            pos++;
        }
    }
}

void output() {
    if (S == vector<int>(M, 0)) {
        int ans = 1;
        for (int i = pos;i < N;i++) {
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