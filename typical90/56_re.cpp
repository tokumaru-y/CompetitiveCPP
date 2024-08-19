#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, S;
vector<pair<int, int>> AB;
vector<vector<bool>> dp;


void input() {
    cin >> N >> S;
    rep(i, N) {
        int a, b;cin >> a >> b;
        AB.push_back(make_pair(a, b));
    }
}

void solve() {
    dp.resize(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;

    for (int i = 0;i < N;i++) {
        auto ab = AB[i];
        int a = ab.first;int b = ab.second;
        for (int j = 0;j <= S;j++) {
            if (j - a >= 0 && dp[i][j - a]) {
                dp[i + 1][j] = true;
            }
            if (j - b >= 0 && dp[i][j - b]) {
                dp[i + 1][j] = true;
            }

        }
    }
}

void output() {
    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return;
    }


    vector<char> ans;
    int j = S;
    for (int i = N;i > 0;i--) {
        auto ab = AB[i - 1];
        int a = ab.first, b = ab.second;
        if (j - a >= 0 && dp[i - 1][j - a]) {
            ans.push_back('A');
            j -= a;
            continue;
        }
        else if (j - b >= 0 && dp[i - 1][j - b]) {
            ans.push_back('B');
            j -= b;
            continue;
        }
    }

    reverse(ans.begin(), ans.end());
    rep(i, N)cout << ans[i];
    cout << endl;
}

int main()
{
    input();
    solve();
    output();
}