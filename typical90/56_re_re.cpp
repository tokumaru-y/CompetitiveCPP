#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, S;
vector<vector<bool>>dp;
vector<int>A;
vector<int>B;

void input() {
    cin >> N >> S;
    dp.resize(N + 1, vector<bool>(100010, false));
    A.resize(N);B.resize(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
}

void solve() {
    dp[0][0] = true;
    for (int i = 0;i < N;i++) {
        int a = A[i], b = B[i];
        for (int j = 0;j <= 100000;j++) {
            int aj = j - a;int bj = j - b;
            if (aj >= 0 && dp[i][aj])dp[i + 1][j] = true;
            if (bj >= 0 && dp[i][bj])dp[i + 1][j] = true;
        }
    }
}

void output() {
    if (dp[N][S] == false) {
        cout << "Impossible" << endl;
    }
    else {
        vector<char>ans;
        int i = N;int j = S;
        while (i > 0) {
            int a = A[i - 1];int b = B[i - 1];
            if (j - a >= 0 && dp[i - 1][j - a]) {
                j -= a;
                ans.push_back('A');
            }
            else if (j - b >= 0 && dp[i - 1][j - b]) {
                j -= b;
                ans.push_back('B');
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        for (auto a : ans) {
            cout << a;
        }
        cout << endl;
    }
}

int main()
{
    input();
    solve();
    output();
}