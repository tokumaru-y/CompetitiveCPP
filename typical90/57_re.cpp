#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> switches;
vector<int>S;
int pos = 0;

void input() {
    cin >> N >> M;
    switches.resize(N, vector<int>(M, 0));
    rep(i, N) {
        int t, x;
        cin >> t;
        rep(j, t) {
            cin >> x;
            switches[i][--x] = 1;
        }
    }

    S.resize(M, 0);
    rep(i, M)cin >> S[i];
}

void solve() {
    for (int row = 0;row < M;row++) {
        bool found = false;
        for (int line = pos;line < N;line++) {
            if (switches[line][row] == 1) {
                if (line != pos) { swap(switches[pos], switches[line]); }
                found = true;break;
            }
        }

        if (found) {
            for (int line = pos;line < N;line++) {
                if (line != pos && switches[line][row] == 1) {
                    for (int rr = row;rr < M; rr++) {
                        switches[line][rr] ^= switches[pos][rr];
                    }
                }
            }

            if (S[row] == 1) {
                for (int rr = row;rr < M;rr++) {
                    S[rr] ^= switches[pos][rr];
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