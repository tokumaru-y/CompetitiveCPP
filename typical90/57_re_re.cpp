#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>>A;
vector<int>S;
int pos = 0;
ll ans = 1;
ll MOD = 998244353;

void input() {
    cin >> N >> M;
    A.resize(N, vector<int>(M, 0));
    S.resize(M);
    rep(i, N) {
        int t;cin >> t;
        rep(j, t) {
            int a;cin >> a;a--;
            A[i][a] = 1;
        }
    }
    rep(i, M)cin >> S[i];
}

void solve() {
    for (int line = 0;line < M;line++) {
        bool found = false;
        for (int i = pos;i < N;i++) {
            if (A[i][line] == 1) {
                if (i != pos)swap(A[i], A[pos]);
                found = true;break;
            }
        }

        if (found) {
            rep(i, N) {
                if (i != pos && A[i][line] == 1) {
                    rep(j, M) {
                        A[i][j] ^= A[pos][j];
                    }
                }
            }

            if (S[line] == 1) {
                rep(i, M) {
                    S[i] ^= A[pos][i];
                }
            }
            pos++;
        }
    }
}

void output() {
    if (S == vector<int>(M, 0)) {
        rep(i, N - pos) {
            ans = ans * 2 % MOD;
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