#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, S;
vector<pair<int, int>> AB;
vector<vector<vector<string>>> dp;


void input() {
    cin >> N >> S;
    rep(i, N) {
        int a, b;cin >> a >> b;
        AB.push_back(make_pair(a, b));
    }
}

void solve() {
    dp.resize(N + 1, vector<vector<string>>(100010, vector<string>(2, "x")));
    auto ab = AB[0];int a = ab.first, b = ab.second;
    dp[1][a][0] = "A";
    dp[1][b][1] = "B";

    for (int i = 1;i < N;i++) {
        auto ab = AB[i];
        int a = ab.first;int b = ab.second;
        for (int j = 0;j <= 100000;j++) {
            if (j - a >= 0) {
                if (dp[i][j - a][0] != "x") {
                    dp[i + 1][j][0] = dp[i][j - a][0] + "A";
                }
                else if (dp[i][j - a][1] != "x") {
                    dp[i + 1][j][0] = dp[i][j - a][1] + "A";
                }
            }

            if (j - b >= 0) {
                if (dp[i][j - b][0] != "x") {
                    dp[i + 1][j][1] = dp[i][j - b][0] + "B";
                }
                else if (dp[i][j - b][1] != "x") {
                    dp[i + 1][j][1] = dp[i][j - b][1] + "B";
                }
            }

        }
    }
}

void output() {
    if (dp[N][S][0] != "x") {
        cout << dp[N][S][0] << endl;
    }
    else if (dp[N][S][1] != "x") {
        cout << dp[N][S][1] << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}